var express = require('express');
var morgan = require('morgan');
var path = require('path');
var crypto =require('crypto');
var bodyParser = require('body-parser');
var Pool = require('pg').Pool;
var app = express();
app.use(morgan('combined'));
app.use(bodyParser.json());

var config = {
    user: 'pinakin2050',
    database: 'pinakin2050',
    host: 'db.imad.hasura-app.io',
    port: '5432',
    password:process.env.DB_PASSWORD 
};

app.get('/', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'index.html'));
});


var counter=0;
app.get('/counter',function(req,res){
    counter = counter+1;
    res.send(counter.toString());
});

var names = [];
app.get('/submit-name',function(req,res){
    //get the name from req
    var name = req.query.name;
    names.push(name);
    res.send(JSON.stringify(names));
});

var pool = new Pool(config);
app.get('/db-test',function(req,res)
{
   pool.query('SELECT *FROM test',function(err,result)
   {
       if(err){
           res.status(500).send(err.toString());
        }
        else{
            res.send(JSON.stringify(result.rows));
        }
   });
});



function hash(input,salt){
    var hashed = crypto.pbkdf2Sync(input,salt,10000,512,'sha512');
    return ["pbkdf2","10000",salt,hashed.toString('hex')];
}

app.get('/hash/:input',function(req,res){
   var hashedString = hash(req.params.input,'this-is-random-string');
   res.send(hashedString);
});

app.post('/create-user',function(req,res){
    var username = req.body.username;
    var password = req.body.password;
    var salt = crypto.randomBytes(128).toString('hex');
    var dbstring = hash(password,salt);
    pool.query('INSERT INTO  "user"(username,password) VALUES ($1,$2)',[username,dbstring],function(err,result){
        if(err){
            res.status(500).send(err.toString);
        }else{
            res.send('User successfully created:'+username);
        }
    });
});


app.post('/login',function(req,res){
    var username = req.body.username;
    var password = req.body.password;
    
    pool.query('SELECT * FROM "user" WHERE username= $1',[username],function(err,result){
    
        if(err){
            res.status(500);
        }else{
            
            if(result.rows.length === 0){
                res.status(403).send('USERNAME/PASSWORD IS INCORRECT!!');
            }else{ //match the password 
                var dbString = result.rows[0].password;
                var salt = dbString.split('$')[2];
                var hashedPassword = hash(password,salt);
                if(hashedPassword === dbString){
                    res.send("CREDENTIALS CORRECT...");
                }else{
                    res.status(403).send("USERNAME/PASSWORD IS INVALID!!!");
                }
            }
        }
    });
});



var articles={
        'article-one':{
            title: 'Article One',
            heading: 'Article one',
            date: '12 aug, 2017',
            content:`
                    <P>
                        This is the contents of article one......  This is the contents of article one......This is the contents of article one......This is the contents of article one......   
                    </P>
                    `
        },
        'article-two':{
            title:'Article Two',
            date:'15 Aug',
            heading:'hello its article two',
            content:`
                    <P>
                        This is the contents of article two......  This is the contents of article two......This is the contents of article two......This is the contents of article two......   
                    </P>
                    `
        },
        'article-three':{
            title:'Article Three',
            date:'17 Aug',
            heading:'hello its article three',
            content:`
                    <P>
                        This is the contents of article three......  This is the contents of article three......This is the contents of article three......This is the contents of article three......   
                    </P>
                    `
        }
    };
function createTemplate(data){
    
     var title=data.title;
     var heading=data.heading;
     var content=data.content;
    
    var htmlTemplate=`
            <html>
    <head>
        <title> ${title} </title>
        <meta name="viewport" content="width-device-width,initial-scale=1" />
        <link rel="stylesheet" type="text/css" href="/ui/style.css" />
    </head>
    <body>
      <div class="container">    
        <div>
            <a href='/'>HOME</a> <hr>
        </div>
        
        <div>
            <h1>${heading}</h1>
        </div>

        <div>
            ${content}
        </div>
      </div>
    </body>
</html>
    `;
    return htmlTemplate;
}

app.get('/articles/:articleName',function(req,res){
    var articleName= req.params.articleName;
    res.send(createTemplate(articles[articleName]));
});

app.get('/ui/style.css', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'style.css'));
});

app.get('/ui/madi.png', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'madi.png'));
});

app.get('/ui/main.js', function (req, res) {
  res.sendFile(path.join(__dirname, 'ui', 'main.js'));
});


// Do not change port, otherwise your app won't run on IMAD servers
// Use 8080 only for local development if you already have apache running on 80

var port = 80;
app.listen(port, function () {
  console.log(`IMAD course app listening on port ${port}!`);
});
