var s;
var is;
var total = 50;
var g = 9;
var maxH = 50;
var running = true;

function SelectSort() {
  this.a = new Array();
  this.i = 0;
  this.j = 0;

  for (var i = 0; i < total; i++)
    this.a.push((random() * maxH));

  this.draw = function() {
    for (var i = 0; i < total; i++) {
      if (i == this.i)
        fill(255, 204, 0);
      else if (i == this.j)
        fill('red');
      else
        fill(255);
      rect(i * g, maxH * g - this.a[i] * g, g, this.a[i] * g);

    }
  }

  this.sort = function() {
    // # original sorting algorithm
    // for (var i = 0; i < total; i++)
    //    for (var j = 0; j < total; i++)
    //        if(a[i] > a[j]) swap(a[i], a[j]);

    if (this.i == total) return;

    if (this.a[this.i] > this.a[this.j]) {
      var tmp = this.a[this.i];
      this.a[this.i] = this.a[this.j];
      this.a[this.j] = tmp;
    }

    if (++this.j == total)
      this.j = ++this.i + 1;

  }

}

function InsertSort() {

  this.a = new Array();
  this.i = 1;
  this.j = 1;
  this.tmp = 0;
  this.one_turn_end = true;

  for (var i = 0; i < total; i++) {
    this.a.push((random() * maxH));
  }

  this.draw = function() {
    for (var i = 0; i < total; i++) {
      if (i == this.i)
        fill(255, 204, 0);
      else if (i == this.j)
        fill('red');
      else
        fill(255);
      rect(i * g, maxH * g - this.a[i] * g, g, this.a[i] * g);

    }
  }

  this.sort = function() {

    if (this.i == total) return;

    if (this.one_turn_end)
      this.tmp = this.a[this.i];

    if (this.j == 0 || this.a[this.j - 1] < this.tmp) {
      this.a[this.j] = this.tmp;
      this.j = ++this.i;
      this.one_turn_end = true;
      return;
    }


    this.a[this.j] = this.a[this.j - 1];
    this.one_turn_end = false;
    this.j--;
  }

}

function setup() {
  createCanvas(total * g, maxH * g);
  frameRate(5);
  // s = new SelectSort();
  s = new InsertSort();
}

function draw() {
  background('#fae');
  s.draw();
  if (running)
    s.sort();
}

function keyPressed() {
  if (keyCode == 32)
    running = !running;
}