var c = 25;
var r = 25;
var g = 16;
var s;
var f;

//Object Snake
function Snake() {
  this.x = 0;
  this.y = 0;
  this.sx = 0;
  this.sy = 1;


  //similar with queue
  this.body = [
    [this.x, this.y]
  ];

  this.draw = function() {
    fill(255);
    for (var i = 0; i < this.body.length; i++)
      rect(this.body[i][0] * g, this.body[i][1] * g, g, g);
    fill(0, 255, 0);
    rect(this.x * g, this.y * g, g, g);
  }
  
  this.setDir = function(dx, dy){
   	this.sx = dx;
    this.sy = dy;
  }

  this.update = function() {
    //or it will disappear while outside the canvas
    this.x = constrain(this.x + this.sx, 0, r - 1);
    this.y = constrain(this.y + this.sy, 0, c - 1);
    
    //key logic
    this.body.pop();
    this.body.unshift([this.x, this.y]);
  }

  this.canEat = function(f) {
		return this.x == f.x && this.y == f.y;
  }

  //push new empty coordinates
  this.eat = function() {
		this.body.push([]);
  }

}

function generateFood(){
  //randomly return a position
  var v = createVector(floor(random() * c), floor(random() * r));
  return v;
}

function setup() {
  createCanvas(c * g, r * g);
  frameRate(10);
  s = new Snake();
	f = new generateFood();
}

function draw() {
  background(30);
  s.update();
  s.draw();
  fill(0, 0, 255);
  rect(f.x * g, f.y * g, g, g);
  if(s.canEat(f)){
    s.eat(f);
    f = new generateFood();
  }
}

function keyPressed() {
  if (keyCode == LEFT_ARROW) {
    s.setDir(-1, 0);
  } else if (keyCode == RIGHT_ARROW) {
    s.setDir(1, 0);
  }else if (keyCode == UP_ARROW) {
    s.setDir(0, -1);
  }else if (keyCode == DOWN_ARROW) {
    s.setDir(0, 1);
  }
}