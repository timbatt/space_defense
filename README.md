# WIP Tower Defense Game - C++ with SFML

## Implementation List (things that need doing):

### Debug Info
- Framerate
- Memory and CPU useage
- Entity and particle count

### JSON Settings Loader
- Read from JSON file to configure settings upon game startup
- Uses https://github.com/nlohmann/json for parsing JSON

### Create Animation Manager for Entities
- Overall animation
- - Set animation time in seconds, set animation frame count from sprite-sheet, loop while entity is alive
- Event-Specific Animation
- - Trigger specific animations upon different events (turret fire, entity dies, etc...)

### Enemies
- Create different enemy types
- Some enemies shoot back, with increasing damage and accuracy as gameplay extends
- Drop packages that contain weapon upgrades and health

### Weapon System
- Add different weapon types
- Weapon types should be toggleable
- Upgrade weapons by collecting dropped upgrades


### Particles
Create particles for corresponding events (different types of explosions, entity deaths, or power ups)

### Sound Effects 
Add more sounds effects corresponding to different types of events.


### Menu/Title Screen
- Simple UI showing game title and basic options.



## Running the Game
You need a C++ compiler and [SFML SDK](https://www.sfml-dev.org/download/) installed.

### Install Dependancies (Debian)
`apt install build-essential libsfml-dev`

#### Clone and Compile
```
git clone https://github.com/timbatt/tower_defense
cd tower_defense
make
```

#### Run
`./main`