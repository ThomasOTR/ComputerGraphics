/** Requirements
 * At least 6 models:
 *   At least 4 distinct geometries:
 *       - Ground : Plane Geometry
 *       - Lamppost: Cylinder & Circle Geometry
 *       - House: Box & Buffer Geometry
 *       - Road: Plane Geometry
 *       - Sidewalk: Box Geometry
 *       - Tree: Cylinder + Sphere Geometry
 *   At least 2 imported Models:
 *    - Car
 *    - Grass / Bushes
 * Demonstrate at least 2 diffrent texture mapping of objects:
 *    - Tree
 *    - House
 *    - Sidewalk
 * 1 Light | Done
 * A skybox | Done
 * Demonstrate transformations(translation,rotation,etc..):
 *    - Car
 * OrbitControls | Done
 * Movement of Camera with Keyboard Controls | Done
 */

import { createHouse } from "./modules/house.js";
import { createTree } from "./modules/tree.js";
import { createRoad } from "./modules/road.js";
import { createLamppost } from "./modules/lamppost.js";
import { createGround } from "./modules/ground.js";
import { createSidewalk } from "./modules/sidewalk.js";

let scene, camera, renderer, controls, gltfLoader, clock;

let light, car, grass;

function init() {
  /* Initialize the necessary parts of THREE.js */
  scene = new THREE.Scene();
  camera = createCamera();
  renderer = createRenderer();
  document.body.appendChild(renderer.domElement);

  /* Initialize added parts of THREE.js */
  clock = new THREE.Clock();
  gltfLoader = new THREE.GLTFLoader();
  controls = new THREE.MapControls(camera, renderer.domElement);
  controls.listenToKeyEvents( window );
  controls.keys = {
    LEFT: 'KeyA', //left arrow
    UP: 'KeyW', // up arrow
    RIGHT: 'KeyD', // right arrow
    BOTTOM: 'KeyS' // down arrow
  }
  controls.enableDamping = true; // an animation loop is required when either damping or auto-rotation are enabled
	controls.dampingFactor = 0.05;

  /* Calling functions to create a Skybox, create light and building the environment */
  createSkybox();
  createLight();
  createEnvironment();

  /* EventListener to call our function to update the position of the camera by keyboardcontrols */
  document.addEventListener("keydown", onDocumentKeyDown, false);

  /* Start render loop */
  animate();
}

/* Creates a new Perspective Camera, positions it */
function createCamera() {
  let PC = new THREE.PerspectiveCamera(
    75,
    window.innerWidth / window.innerHeight,
    0.1,
    1000
  );
  PC.position.set(15, 15, 0);
  return PC;
}

/* Creates the renderer, enables the shadowmap */
function createRenderer() {
  let r = new THREE.WebGLRenderer({ antialias: true, alpha: true });
  r.setSize(window.innerWidth, window.innerHeight);
  r.shadowMap.enabled = true;
  return r;
}

/* Adds a Skybox by using the TextureLoader */
function createSkybox() {
  let directions = [
    "right.png",
    "left.png",
    "top.png",
    "bottom.png",
    "back.png",
    "front.png",
  ];
  let materialArray = [];
  for (let i = 0; i < 6; i++) {
    materialArray.push(
      new THREE.MeshBasicMaterial({
        map: new THREE.TextureLoader().load(`./res/skybox/${directions[i]}`),
        side: THREE.BackSide,
      })
    );
  }
  let skyGeometry = new THREE.BoxGeometry(100, 100, 100);
  let skyBox = new THREE.Mesh(skyGeometry, materialArray);
  scene.add(skyBox);
}

/* Creates a SpotLight and enables castShadow */
function createLight() {
  light = new THREE.SpotLight(0xffa95c, 4);
  light.position.set(-50, 50, 50);
  light.castShadow = true;
  scene.add(light);
}

function createEnvironment() {
  /* Adds a layer for the environment to build on. */
  let ground = createGround();
  ground.position.set(0, 0, 0);
  scene.add(ground);

  /* Builds a house and positions it */
  let house = createHouse();
  house.position.set(-3, 2.5, -20);
  let house2 = createHouse();
  house2.position.set(-3, 2.5, 0);
  let house3 = createHouse();
  house3.position.set(-3, 2.5, 20);

  scene.add(house);
  scene.add(house2);
  scene.add(house3);

  /* Adds a forest to the environment */
  let forest = [];
  let treeX = 5;
  let treeZ = -25;
  for (let j = 0; j < 5; j++) {
    for (let i = 0; i < 11; i++) {
      if (treeZ <= 25) {
        forest[(j, i)] = createTree();
        forest[(j, i)].position.set(treeX, 2.5, treeZ);
        scene.add(forest[(j, i)]);
        treeZ += 5;
      }
    }
    treeZ = -25;
    treeX += 3;
  }
  /* Adds some random trees to the environment */
  let tree = createTree();
  tree.position.set(-35, 2.5, -25);
  let tree2 = createTree();
  tree2.position.set(-35, 2.5, -15);
  let tree3 = createTree();
  tree3.position.set(-35, 2.5, -5);
  let tree4 = createTree();
  tree4.position.set(-35, 2.5, 5);
  let tree5 = createTree();
  tree5.position.set(-35, 2.5, 15);
  let tree6 = createTree();
  tree6.position.set(-35, 2.5, 25);

  scene.add(tree);
  scene.add(tree2);
  scene.add(tree3);
  scene.add(tree4);
  scene.add(tree5);
  scene.add(tree6);

  let roadlength = 58;

  /* Adds 2 roads for cars to drive on */
  let road = createRoad(roadlength);
  road.position.set(10, 0.1, 29);
  scene.add(road);
  let road2 = createRoad(roadlength);
  road2.position.set(-16, 0.1, 29);
  scene.add(road2);

  /* Adds some sidewalks to walk on */
  let sidewalk = createSidewalk(roadlength);
  sidewalk.position.set(6.5, 0.3, 29);
  scene.add(sidewalk);
  let sidewalk2 = createSidewalk(roadlength);
  sidewalk2.position.set(-13, 0.3, 29);
  scene.add(sidewalk2);
  let sidewalk3 = createSidewalk(roadlength);
  sidewalk3.position.set(-19, 0.3, 29);
  scene.add(sidewalk3);

  /* Adds a imported car to the environment */
  car = new THREE.Object3D();
  gltfLoader.load("./res/models/car/source/charger.glb", function (object) {
    car = object.scene;
    car.position.set(11, 0.7, 29);
    car.scale.set(5, 5, 5);
    car.rotation.y = -Math.PI / 2;

    scene.add(car);
  });

  /* Adds some imported grass/bushes to the environment */
  grass = new THREE.Object3D();
  gltfLoader.load("./res/models/grass/grass2.glb", function (object) {
    grass = object.scene.children[0];
    grass.scale.set(0.05, 0.05, 0.05);

    let grassArr = [];
    for (let g = -25; g <= 25; g++) {
      grassArr[g] = grass.clone();
      grassArr[g].position.set(4.5, 0.2, g);
      scene.add(grassArr[g]);
    }
  });

  /* Adds some lampposts to the environment */
  let lp1 = createLamppost();
  lp1.position.set(6.5, 2.3, 17);
  let lp2 = createLamppost();
  lp2.position.set(13, 1.8, 2);
  let lp3 = createLamppost();
  lp3.position.set(6.5, 2.3, -13);
  let lp4 = createLamppost();
  lp4.position.set(13, 1.8, -28);
  scene.add(lp1);
  scene.add(lp2);
  scene.add(lp3);
  scene.add(lp4);

  let lp5 = createLamppost();
  lp5.position.set(-13, 2.3, 17);
  let lp6 = createLamppost();
  lp6.position.set(-19, 1.8, 2);
  let lp7 = createLamppost();
  lp7.position.set(-13, 2.3, -13);
  let lp8 = createLamppost();
  lp8.position.set(-19, 1.8, -28);
  scene.add(lp5);
  scene.add(lp6);
  scene.add(lp7);
  scene.add(lp8);
}

function onDocumentKeyDown(event) {
  let increment = 1;
  switch (event.which) {
    /* Q */
    case 81:
      camera.position.y += increment;
      break;
    /* E */
    case 69:
      if (camera.position.y > 1.5) camera.position.y -= increment;
      break;
    /* Esc to toggle autoRotate */
    case 27:
      controls.autoRotate = !controls.autoRotate;
      break;
  }
  camera.updateProjectionMatrix();
}

function animate() {
  /* Animates the car */
  let delta = clock.getDelta();
  car.position.z -= 3.2 * delta;
  if (car.position.z <= -20) car.position.z = 30;

  /* Updates the OrbitControls and the Renderer */
  controls.update();
  renderer.render(scene, camera);
  requestAnimationFrame(animate);
}

init();
