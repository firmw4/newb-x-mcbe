# Newb X Pineapple

**Newb X Pineapple** is a RenderDragon successor to the legacy GLSL shader, [Newb Shader](https://github.com/devendrn/newb-shader-mcbe). An aesthetic shader with soft lighting and better fog. It supports Minecraft Bedrock 1.21 (Windows/Android/*iOS).

> [!WARNING]
> This is an experimental repository, breaking changes are made often.

![Screenshots](docs/screenshots_nr.jpg "Newb Renewed")

## Downloads

Nightly builds for Android (ESSL) and Windows (DX) can be found at the [Discord server](https://discord.gg/newb-community-844591537430069279).

## Installation

> [!NOTE]
> Shaders are not officially supported on Minecraft Bedrock. The following are unofficial ways to load shaders.

**Linux:** [mcpelauncher-manifest](https://github.com/minecraft-linux/mcpelauncher-ui-manifest)
1. Extract material.bin files from shader mcpack / build materials from source.
2. Move these files to data root `mcpelauncher/versions/1.20.x/assets/renderer/materials/`. (Make sure to backup all files in this folder first)
3. Import the resource pack and activate it in global resources.

**Windows:**
1. Use [BetterRenderDragon](https://github.com/ddf8196/BetterRenderDragon) to enable MaterialBinLoader.
2. Import the resource pack and activate it in global resources.

**Android:**
1. Install [Patched Minecraft App](https://devendrn.github.io/renderdragon-shaders/shaders/installation/android#using-patch-app)
2. Import the resource pack and activate it in global resources.

## Building

### Install dependencies
- [Git](https://git-scm.com/)
- [Python](https://www.python.org/) 3.11 or higher required
- Python packages [lazurite](https://veka0.github.io/lazurite/#installation) and [rich](https://rich.readthedocs.io/en/stable/introduction.html#installation)

### Get source code
```
git clone https://github.com/devendrn/newb-x-mcbe/
cd newb-x-mcbe
```

### Setup build environment
> [!NOTE]
> On Windows, you should use `.\build.bat` instead of `./build.sh` for all following commands. 
```
./build.sh setup
```
This will download shaderc binary and material data required to build shader.

### Compile specific shader materials
```
./build.sh mats
```  
Compiled material.bin files will be inside `build/<platform>/`  
**Command usage:**
```
usage: build mats [-h] [-p {android,windows,merged,ios}] [-m M [M ...]] [-s S]

options:
  -h, --help            show this help message and exit
  -p {android,windows,merged,ios}
                        build profile
  -m M [M ...]          build materials (eg: Sky)
  -s S                  subpack config to use (eg: NO_WAVE)
```

### Compile and build full shader pack
```
./build.sh pack
```
The final mcpack will be inside `build/`.  
**Command usage:**
```
usage: build pack [-h] [-p {android,windows,merged,ios}] [--no-zip] [--no-label] [-v V]

options:
  -h, --help            show this help message and exit
  -p {android,windows,merged,ios}
                        build profile
  --no-zip              don't make archive
  --no-label            don't label materials
  -v V                  version number eg: 46
```

## Development

Clangd can be used to get code completion and error checks for source files inside include/newb. Fake bgfx header and clangd config are provided for the same.
- **Neovim** (NvChad): Install clangd LSP from Mason.
- **VSCode**: Install [vscode-clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) extension.
