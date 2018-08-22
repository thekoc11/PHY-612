var Particle = {
  radius: 10,
  x: 0,
  y: 0,
  z: 0,

  create: function(x, y, z){
    var obj = Object.create(this);
    obj.setX(x);
    obj.setY(y);
    obj.setZ(z);

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
  getX: function(){
    return this.x;
  },
  getY: function(){
    return this.y;
  },
  getZ: function(){
    return this.z;
  },

  distanceTo: function(p2){
    var X = p2.getX(), Y = p2.getY(), Z = p2.getZ();
    var x = this.x, y = this.y, z = this.z;
    var dist = Math.sqrt((X - z)**2, (Y - y)**2, (Z - z)**2);
    return dist;
  },
};
