import * as THREE from 'three';
import './style.css';



const scene = new THREE.Scene();

//creating the sphere
const geometry = new THREE.SphereGeometry( 3, 64, 64 ); 
const material = new THREE.MeshStandardMaterial({
   color: '#ffff00',
})
const sphere = new THREE.Mesh( geometry, material );
scene.add( sphere );

//sizes
const sizes = {
   width: window.innerWidth,
   height: window.innerHeight
}
//light
const light = new THREE.PointLight(0xffffff, 200, 200);
light.position.set(0,0,10); 
scene.add(light);

//camera
const camera = new THREE.PerspectiveCamera(45,sizes.width/sizes.height, 0.1, 100);
camera.position.z = 100;
scene.add(camera);

//rendering canvas
const canvas = document.querySelector('.webGL');
const renderer = new THREE.WebGLRenderer({canvas});
renderer.setSize(sizes.width,sizes.height);
renderer.render(scene,camera);


//resize
window.addEventListener("resize",() => {
   //sizes
   sizes.width = window.innerWidth
   sizes.height = window.innerHeight

   //update camera
   camera.aspect = sizes.width /sizes.height
   camera.updateProjectionMatrix()
   renderer.setSize(sizes.width,sizes.height)
})

const loop = () => {

 


   renderer.render(scene,camera);
   window.requestAnimationFrame(loop);
}
loop();