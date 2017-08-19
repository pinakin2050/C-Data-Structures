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
                  if(request.status===200)
                   {
                      var counter = request.resposeText;
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


