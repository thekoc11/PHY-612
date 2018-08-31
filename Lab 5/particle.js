var Particle = {
  radius: 10,
  x: 0,
  y: 0,
  z: 0,
  vx: 0,
  vy: 0,
  vz: 0,
  KE: 0,

  create: function(x, y, z){
    var obj = Object.create(this);
    obj.setX(x);
    obj.setY(y);
    obj.setZ(z);
    obj.setVx(-0.5, 0.5);
    obj.setVy(-0.5, 0.5);
    obj.setVz(-0.5, 0.5);
    obj.KE = obj.vx**2 + obj.vy**2 + obj.vz**2;
    return obj;
  },

  setX: function(x){
    this.x = x;
  },
  setY: function(y){
    this.y = y;
  },
  setZ: function(z){
    this.z = z;
  },
  setVx : function(lb, ub){
    this.vx = Math.random() * (ub - lb) + lb;
  },
  setVy : function(lb, ub){
    this.vy = Math.random() * (ub - lb) + lb;
  },
  setVz : function(lb, ub){
    this.vz = Math.random() * (ub - lb) + lb;
  },
  getX: function(){
    return this.x;
  },
  getY: function(){
    return this.y;
  },
  getZ: function(){
    return this.z;
  },

  getKE: function(){
    return this.KE
  },

  getVx: function(){
    return this.vx;
  },
  getVy: function(){
    return this.vy;
  },
  getVz: function(){
    return this.vz;
  },

  distanceTo: function(p2){//follows nearest image convenction
    var X = p2.getX(), Y = p2.getY(), Z = p2.getZ();
    var x = this.x, y = this.y, z = this.z;
    var _x = X - x, _y = Y - y, _z = Z - z;
    _x = _x - 200 * Math.floor(_x/200);
    _y = _y - 200 * Math.floor(_y/200);
    _z = _z - 200 * Math.floor(_z/200);	
    var dist = Math.sqrt(_x**2, _y**2, _z**2);
    return dist;
  },
  
  update: function(t){
    this.setX(this.x + this.vx*t);
    this.setY(this.y + this.vy*t);
    this.setZ(this.z + this.vz*t);
  },
};
