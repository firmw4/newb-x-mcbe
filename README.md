# Newb X Nanas

A RenderDragon shader based on [newb-x-mcbe](https://github.com/devendrn/newb-x-mcbe)

> [!WARNING]
> This is an experimental repository, made for my newb variant, which adds various features and optimizations.

<br>

## Downloads
[v15 stable](https://github.com/devendrn/newb-x-mcbe/releases/tag/v15) (For 1.20.73 or older)  
[v15 beta](https://github.com/devendrn/newb-x-mcbe/releases/tag/v15-dev) (For 1.20.80 or newer)

Nightly builds for Android (ESSL), Windows (DX), and iOS (Metal) can also be found at the [Discord server](https://discord.gg/newb-community-844591537430069279).

My newb variants can be found at https://firmw4.vercel.app/newb-variants/index.html

<br>

## Building

### Install dependencies
- [Git](https://git-scm.com/)
- [Python](https://www.python.org/) 3.11 or higher required
- Python packages:
  - [lazurite](https://veka0.github.io/lazurite/#installation) (Must be `v0.4.0`. Newer or older version may not be supported)
  - [rich](https://rich.readthedocs.io/en/stable/introduction.html#installation) (Must be `v13.x.x`)

### Get source code
```
git clone https://github.com/firmw4/newb-x-mcbe/
cd newb-x-mcbe
```

### Install dependencies from requirements.txt
*Skip if you already have installed those versions.*
```
python -m pip install -r requirements.txt
```

### Setup build environment
> [!NOTE]
> On Windows, run `.\build.bat` instead of `./build.sh` for all following commands.
```
./build.sh setup
```
This will download shaderc binary and material data required to build shader.

<br>

### Compile specific shader materials
```
./build.sh mats
```
Compiled material.bin files will be inside `build/<platform>/`

**Command usage:**
```
usage: build mats [-h] [-p {android,windows,merged,ios}] [-m M [M ...]] [-s S]

options:
