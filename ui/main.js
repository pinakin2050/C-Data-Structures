console.log('Loaded!');

/*var img = document.getElementById("main-img");
var marginLeft=0;
function moveRight(){
      marginLeft = marginLeft+5;
      img.style.marginLeft=marginLeft+'px';
}
img.onclick = function(){
   var interval = setInterval(moveRight,5);   
};*/

/*
//counter code
var button = document.getElementById("counter");
button.onclick = function()
   {
            //create req object
            var request = new XMLHttpRequest();
            
            //caputer res & store it in a variable
          request.onreadystatechange = function()
          {
              if(request.readyState===XMLHttpRequest.DONE)
                {
                  //take some action
                  if(request.status === 200)
                   {
                      var counter = request.responseText;
                      var span = document.getElementById("count");
                      span.innerHTML = counter.toString();
                   }
                }
                //not done yet
          };
          
        //make http req
        request.open('GET','http://pinakin2050.imad.hasura-app.io/counter',true);
        request.send(null);
    };
*/
/*
//submit name
var submit = document.getElementById("submit_btn");
submit.onclick = function()
{
    //create req object
    var request = new XMLHttpRequest();
    
    //capture res & store it in a var
    request.onreadystatechange = function()
    {
        if(request.readyState===XMLHttpRequest.DONE)
                {
                  //take some action
                  if(request.status === 200)
                   {
                      var names = request.responseText;
                      names = JSON.parse(names);
                      var list ='' ;
                      for(var i=0;i<names.length;i++)
                        {
                            list += '<li>'+names[i]+'</li>';
                        }
                      var ui = document.getElementById("namelist");
                      ui.innerHTML = list;
                   }
                }
                //not done yet
          };
          //make req
          var nameInput = document.getElementById("name");
          var name = nameInput.value;
          request.open('GET','http://pinakin2050.imad.hasura-app.io/submit-name?name='+name,true);
          request.send(null);
    };
*/
//submit username & password
var submit = document.getElementById('submit_btn');
submit.onclick = function()
{
    //create req object
    var request = new XMLHttpRequest();
    
    //capture res & store it in a var
    request.onreadystatechange = function()
    {
        if(request.readyState===XMLHttpRequest.DONE)
                {
                  //take some action
                  if(request.status === 200)
                   {
                      alert("Logged in successfully..");
                   }else if(request.status===403){
                       alert("Logged in successfully..");
                   }else if(request.status===500){
                       alert("Something went wrong!!");
                   }
                }
                //not done yet
          };
          //make req
          var username= document.getElementById('username').value;
          var password= document.getElementById('password').value;
          request.open('POST','http://pinakin2050.imad.hasura-app.io/login',true);
          request.setRequestHeader('Content-Type', 'application/json');
          request.send(JSON.stringify({username: username,password: password}));
    };










