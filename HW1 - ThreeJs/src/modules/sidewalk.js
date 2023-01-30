export function createSidewalk(length) {
  /* Creates a group to piece all the sidewalk tiles together */
  let group = new THREE.Group();
  /* Loads the trottoir texture  */
  const texture = new THREE.TextureLoader().load(
    "./res//textures/trottoir.jpg"
  );
  /* Setting the geometry and material of the Sidewalk tiles */
  let geometry = new THREE.BoxGeometry(2, 0.5, 2);
  let material = new THREE.MeshBasicMaterial({
    map: texture,
    side: THREE.DoubleSide,
  });

  /* A loop to create and position the tiles on z-position i */
  var tile = [];
  for (let i = -length; i <= 0; i += 2) {
    tile[i] = new THREE.Mesh(geometry, material);
    tile[i].position.z = i;
    group.add(tile[i]);
  }
  return group;
}
