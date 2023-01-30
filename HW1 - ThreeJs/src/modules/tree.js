export function createTree() {
  /* Creates a group to piece the stem and leaves together */
  let tree = new THREE.Group();

  /* Creates a Stem with a CylinderGeometry and a LambertMaterial with the emissive properties to make the sun shining on the stem */
  let stemGeometry = new THREE.CylinderGeometry(0.5, 0.5, 5, 8);
  let stemMaterial = new THREE.MeshLambertMaterial({
    color: 0x7d5a4f,
    emissive: 0x4e3524,
  });
  let stem = new THREE.Mesh(stemGeometry, stemMaterial);
  stem.position.set(10, 0, 1);
  stem.castShadows = true;
  stem.recieveShadows = true;
  tree.add(stem);

  const leavesTexture = new THREE.TextureLoader().load(
    "./res/textures/leaves.jpg"
  );

  /* Creates the leaves as a Sphere with a leaves texture */
  const geometry = new THREE.SphereGeometry(2, 19, 8);
  const material = new THREE.MeshBasicMaterial({
    map: leavesTexture,
    side: THREE.DoubleSide,
  });
  const leaves = new THREE.Mesh(geometry, material);
  leaves.position.set(10, 3.1, 1);
  tree.add(leaves);

  return tree;
}
