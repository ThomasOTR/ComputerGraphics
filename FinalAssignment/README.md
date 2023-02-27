# Computer Graphics Final Assignment

## Folderstructuur
Voor deze opdracht heb ik een mappenstructuur gemaakt om zo makkelijk bij elkaar horende files te kunnen vinden. Deze heb ik ook in de solution in Visual Studio toegevoegd:
- Animations
- Models
- Objects
- PrimitiveMeshes
- Shaders
- Textures

## Wat is er in de uitwerking te vinden?

### Models
De volgende modellen zijn aanwezig in deze final assignment uitwerking:

- Car
- lamppost
- sidewalk
- trashbin
- tree

en House. Deze bestaat uit 4 PrimitiveMeshes, wat een van de vereisten was.
### PrimitiveMeshes
In deze uitwerking heb ik 4 vormen gemaakt door middel van eigen code:
- Cube
- Plane
- Pyramid
- TriangularPrism
### Designed Obj-files
Daarnaast heb ik ook verschillende objecten gemaakt in Blender. Een deel van de objecten heb ik opgedeeld in verschillende onderdelen om ze zo los van elkaar textures / kleuren te kunnen
- Tree
    - Trunk
    - Leaves
- Lamppost
    - Top
    - Light
    - Pole
- Trashbin
    - container
    - lid
- Bench
- Fence

### Animations
TODO:

## Wat heb ik gedaan in deze uitwerking wat ik graag wil benoemen?

De volgende bonus onderdelen heb ik toegevoegd:
- Mouse movement i.p.v. IJKL
- Het veranderen van de y-position in Drone mode (Q/E)

Ik heb bij het maken van deze opdracht erg gelet op modularity. 

Ik heb classes gemaakt voor elk type object in de wereld: PrimitiveMesh, Object, Model. Deze zijn allemaal subclasses van Entity. Dit heb ik gedaan omdat ik wist dat ik verschillende code zou hergebruiken, omdat alle objecten dit nodig zouden hebben.

Daarnaast heb ik een Environment builder gemaakt, deze laad alle objecten in de wereld in en kan deze bufferen en renderen. Deze is makkelijk uit te breiden met meer objecten in de wereld wanneer dit nodig is, omdat alle objecten modulair zijn.

Van veel onderdelen kunnen er meer toegevoegd worden.
- Animations. Inherited van Animation.h
- Materials. Inherited van Material.h
- Models. Inherited van Model.h
- Objects. Laad andere Objecten in door  paths toe te voegen naar andere objecten
- PrimitiveMeshes. Inherited van PrimitiveMesh.h





