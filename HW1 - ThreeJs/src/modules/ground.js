export function createGround() {
  /* Creates a big plane with a specific color green on both sides */
  let g = new THREE.PlaneGeometry(60, 60);
  let m = new THREE.MeshBasicMaterial({
    color: 0x138510,
    side: THREE.DoubleSide,
  });
  let ground = new THREE.Mesh(g, m);

  /* This rotation is needed to change the plane from vertical to horizontal */
  ground.rotation.x = -Math.PI / 2;

  return ground;
}
