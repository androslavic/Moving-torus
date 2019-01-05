let data = {}; // Global object to hold results from the loadJSON call

let fontsize = 40;

// Put any asynchronous data loading in preload to complete before "setup" is run
function preload() {
  data = loadJSON('http://127.0.0.1:8080/data.json');
}


function setup() {
  createCanvas(600, 500,WEBGL);
  i=2;
  j=0;
  frameRate(24);

  xRot=(PI * parseInt(data[i].x)/1000);
  yRot=(PI * parseInt(data[i].y)/1000);
  zRot=(PI * parseInt(data[i].z)/1000);
}

function draw() {

  j=j+1;
  if (j%3==0)
  {i=i+1;
  background(255);
  xRot=xRot+(PI * parseInt(data[i].x)/1000);
  yRot=yRot+(PI * parseInt(data[i].y)/1000);
  zRot=zRot+(PI * parseInt(data[i].z)/1000);
  console.log(cos(xRot) + cos(yRot) + cos(zRot));
}
  rectMode(CENTER);
  fill(0,0,225);
  rotateX(cos(xRot));
  rotateY(cos(yRot));
  rotateZ(cos(zRot));
  torus(100,10);

  }
