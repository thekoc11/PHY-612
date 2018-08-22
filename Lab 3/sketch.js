var p = []; //Array of particles
var tempP = Particle.create(0, 0, 0);
var _dist = 0.0;//distance between two particles
var c = 0;
var noOfParticles = 10
function setup(){
  createCanvas(windowWidth, windowHeight, WEBGL);
  main();//function where all the magic happens
}

function draw(){
  background(0);
  //lights();
  noFill();
  stroke(255);
  // pushMatrix();
  // noStroke();
  box(200);//a cube of side 200
  // popMatrix();


  noStroke();
  fill(255);

  for(var i = 0; i < p.length; i+= 1){
    push();//reset the pointer, bring it back to origin
    translate(p[i].getX(), p[i].getY(), p[i].getZ());
    sphere(p[i].radius);
    pop();
  }
}

function main(){
  while(p.length < noOfParticles){
    tempP = Particle.create((Math.random()*2 - 1/*generatees a random number between -1, 1*/) * 100, (Math.random()*2 - 1) * 100, (Math.random()*2 - 1) * 100);
    var l = p.length;
    if(l != 0){
      for(var j = 0; j < l; j+=1){
        _dist = tempP.distanceTo(p[j]);
        console.log("the value of dist is ", _dist);
        if(_dist < 20){
          c = c+1;
        }
      }
    }
    console.log("The valur of C is ", c);
    if(c == 0){
      console.log("The X, Y, Z spawn points are", tempP.getX(), tempP.getY(), tempP.getZ());
      p.push(tempP);
      console.log("length of tye array is", p.length);
    }
    c = 0;
  }

}
