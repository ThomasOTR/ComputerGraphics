export function createHouse() {
  /* Load the 2 textures we need */
  let tl = new THREE.TextureLoader();
  const wallTexture = tl.load("./res/textures/brickwall.jpg");
  const roofTexture = tl.load("./res/textures/rooftiles.jpg");

  /* Creates a group to piece the base and the roof together */
  let house = new THREE.Group();

  /* Creates the base of the house */
  let baseGeometry = new THREE.BoxGeometry(9, 5, 12);
  let baseMaterial = new THREE.MeshBasicMaterial({
    map: wallTexture,
    side: THREE.DoubleSide,
  });
  let base = new THREE.Mesh(baseGeometry, baseMaterial);
  house.add(base);

  /* Creates a BufferGeometry for the roof with the array of Vectors */
  let pts = [
    new THREE.Vector3(4.5, 3.5, 4.5),
    new THREE.Vector3(0, 0, -1),
    new THREE.Vector3(0, 0, 11),
    new THREE.Vector3(9, 0, 11),
    new THREE.Vector3(9, 0, -1),
  ];
  let roofGeometry = new THREE.BufferGeometry().setFromPoints(pts);

  /* Set the Indexes for the Geometry and Compute the VertexNormals; */
  roofGeometry.setIndex([0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 1, 1, 3, 2, 1, 4, 3]);
  roofGeometry.computeVertexNormals();

  /* Create a Mesh with the roofTexture and the Buffer geometry */
  let roofMaterial = new THREE.MeshBasicMaterial({ map: roofTexture });
  /* wil nog niet zoals ik wil, pakt het plaatje niet */
  let mesh = new THREE.Mesh(roofGeometry, roofMaterial);
  mesh.position.set(-4.5, 2.5, -5);
  house.add(mesh);

  return house;
}
