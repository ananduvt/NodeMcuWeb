const char MAIN_page[] PROGMEM = R"=====(<html lang="en">
  <head>
    <meta
      name="viewport"
      content="width=device-width, initial-scale=1.0, user-scalable=no"
    />
    <title>LED Control</title>
    <style>
      html {
        font-family: Helvetica;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
        background: black;
      }
      body {
        margin-top: 50px;
		color:white;
      }
      h1 {
        color: white;
        margin: 50px auto 30px;
      }
      h3 {
        color: white;
        margin-bottom: 50px;
      }
	  
      button {
        display: inline-block;
		background-color: #1abc9c;
        border: none;
        color: white;
        padding: 10px 20px;
        text-decoration: none;
        font-size: 16px;
        margin: 5px auto;
        cursor: pointer;
        border-radius: 10px;
      }
	  
	  .active {
		background-color:#079213 !important;
	  }
      
      p {
        font-size: 14px;
        color: white;
        margin-bottom: 10px;
      }
      .slider {
        width: 180px;
        margin-top: 10px;
      }
      .picker {
        width: 224px;
        height: 30px;
        border: 2px solid white;
        border-radius: 10px;
      }
    </style>
  </head>
  <body>
    <h1>Led Control</h1>
    <div class="slidecontainer">
      <p>Brightness : <span id="param"></span></p>
      <input
        type="range"
        min="3"
        max="255"
        class="slider"
        id="myRange"
        value="150"
      />
    </div>
    
    <div class="slidecontainer">
      <p>Delay : <span id="param2"></span></p>
      <input
        type="range"
        min="50"
        max="2000"
        class="slider"
        id="myRange2"
        value="1000"
      />
    </div>
    <div class="colorpicker">
      <p>Color Picker : <span id="color"></span></p>
      <input class="picker" type="color" id="picker" value="#ffffff" onchange="colorPicked(this.value)" />
    </div>
	
	<div id="modes">
		<h2>Modes</h2>
		<button id="single" class="active" onclick="modeClicked(this.id)">Single</button>
		<button id="strobe" onclick="modeClicked(this.id)">Strobe</button>
		<button id="rainbow" onclick="modeClicked(this.id)">Rainbow</button>
		<button id="runner" onclick="modeClicked(this.id)">Runner</button>
		<button id="pulse" onclick="modeClicked(this.id)">Pulse</button>
		<button id="midSplit" onclick="modeClicked(this.id)">Mid Split</button>
	</div>
	
  </body>
  <script>
    
    var slider = document.getElementById("myRange");
    var output1 = document.getElementById("param");
    output1.innerHTML = slider.value;
    slider.onchange = function () {
      output1.innerHTML = this.value;
	  sendRequest("setBrightness?brightness="+this.value);
    };
	
    var slider2 = document.getElementById("myRange2");
    var output12 = document.getElementById("param2");
    output12.innerHTML = slider2.value;
    slider2.onchange = function () {
      output12.innerHTML = this.value;
	  sendRequest("setDelay?delay="+this.value);
    };

	/* 
	function changeB(val){
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
          
        }
      };
        xhttp.open("GET", "setBrightness?brightness=" + val, true);
        xhttp.send();
    }
	
    function changeD(val){
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
        xhttp.open("GET", "setDelay?delay=" + val, true);
        xhttp.send();
    }
	*/
	function colorPicked(value){
		sendRequest("setColor?color="+value);
	}
	function sendRequest(param){
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function () {
			if (this.readyState == 4 && this.status == 200) {
			  console.log(this.responseText);
			}
		};
        xhttp.open("GET", param , true);
		console.log("Sending : " + param);
        xhttp.send();
	}
	
    var picker = document.getElementById("picker");
    var output2 = document.getElementById("color");
    output2.innerHTML = picker.value;
    picker.oninput = function () {
      output2.innerHTML = this.value;
    };
	
	function modeClicked(value){
		sendRequest("setMode?mode="+value);
		var buttons = document.getElementById("modes");
		
		buttons.childNodes.forEach(function(child){
			if(child.id == value){
				child.classList.add('active');
			}
			else{
				if(typeof child.classList !== 'undefined'){
					child.classList.remove('active');
				}
			}
		});
	}
  </script>
</html>
)=====";
