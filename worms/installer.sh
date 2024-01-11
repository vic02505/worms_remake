#!/bin/bash

sudo rm -rf build

echo "=== INSTALACIÓN DE DEPENDENCIAS ==="
echo ""
echo ">> Instalando 'cmake'..."
sudo apt-get install cmake
echo ""
echo ">> Instalando 'libsdl2-dev'..."
sudo apt-get install libsdl2-dev
echo ""
echo ">> Instalando 'libsdl2-image-dev'..."
sudo apt-get install libsdl2-image-dev
echo ""
echo ">> Instalando 'libsdl2-ttf-dev'..."
sudo apt-get install libsdl2-ttf-dev
echo ""
echo ">> Instalando 'libsdl2-mixer-dev'..."
sudo apt-get install libsdl2-mixer-dev
echo ""
echo ">> Instalando 'build-essential'..."
sudo apt-get install build-essential
echo ""
echo ">> Instalando 'qtcreator'..."
sudo apt-get install qtcreator
echo ""
echo ">> Instalando 'qtbase5-dev'..."
sudo apt-get install qtbase5-dev
echo ""
echo ">> Instalando Box2D"
cd Box2D
./build.sh
cd ..
echo ""
echo "Instalación de dependencias finalizada."
echo ""

echo "=== INSTALACIÓN DEL JUEGO ==="
mkdir build
cd build
cmake ..
make -j4
echo ""
echo "Instalación de juego finalizada."
echo ""
