export function createLamppost() {
  /* Creates a group to piece the post, lamp and top together */
  let lamppost = new THREE.Group();

  /* Creates the post of the lamppost as a CylinderGeometry with a specific gray color */
  const postGeometry = new THREE.CylinderGeometry(1.5, 3, 36, 8);
  const postMaterial = new THREE.MeshBasicMaterial({ color: 0x706e6e });
  const post = new THREE.Mesh(postGeometry, postMaterial);
  lamppost.add(post);

  /** Creates the lamp of the Lamppost as a Cylinder
   *  To make the lamp more realistic, we made the bottom radius smaller than the top radius
   *  and we added some opacity.
   **/
  const lampGeometry = new THREE.CylinderGeometry(7.5, 1.5, 7.8, 8);
  const lampMaterial = new THREE.MeshBasicMaterial({
    color: 0xffa95c,
    transparent: true,
    opacity: 0.7,
  });
  const lamp = new THREE.Mesh(lampGeometry, lampMaterial);

  /* The y-position set is to put the lamp on the post. */
  lamp.position.y = 22;

  lamppost.add(lamp);

  /* Creates the top of the lamppost as a CircleGeomoetry and the same color of the post */
  const topGeometry = new THREE.CircleGeometry(10, 8);
  const topMaterial = new THREE.MeshBasicMaterial({
    color: 0x706e6e,
    side: THREE.DoubleSide,
  });
  const top = new THREE.Mesh(topGeometry, topMaterial);

  /* The y-position set is to put the Top on top of the lamp*/
  top.position.y = 26;
  /* This rotation is needed to change the circle from vertical to horizontal */
  top.rotation.x = -Math.PI / 2;

  lamppost.add(top);

  /**
   * To use the CylinderGeometry well, we created the meshes a bit bigger.
   * At the end we now scale is down to let it fit in the environment
   **/
  lamppost.scale.set(0.1, 0.1, 0.1);

  return lamppost;
}
