export function createRoad(length) {
  /* Creates a group to piece all the road tiles together */
  let group = new THREE.Group();

  /* Setting the geometry and material of the Sidewalk tiles */
  let geometry = new THREE.PlaneGeometry(5, 2);
  let material = new THREE.MeshBasicMaterial({
    color: 0x5b5b5b,
    side: THREE.DoubleSide,
  });

  /* A loop to create and position the tiles on z-position i */
  var tile = [];
  for (let i = -length; i <= 0; i += 2) {
    tile[i] = new THREE.Mesh(geometry, material);
    tile[i].position.z = i;
    tile[i].rotation.x = Math.PI / 2;
    group.add(tile[i]);
  }
  return group;
}
