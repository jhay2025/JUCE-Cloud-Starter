# JUCE Cloud Starter 🚀

Este proyecto está configurado para programar en **JUCE** directamente desde tu navegador usando **GitHub Codespaces**, sin necesidad de descargar nada a tu computadora local.

## Cómo empezar:
1. Haz clic en el botón verde **"Code"**.
2. Selecciona la pestaña **"Codespaces"**.
3. Haz clic en **"Create codespace on main"**.
4. Una vez dentro de VS Code Web:
   - Abre la Terminal (Ctrl + `).
   - Instala librerías de audio necesarias en el Codespace: `sudo apt-get update && sudo apt-get install -y libasound2-dev libjack-jackd2-dev libfreetype6-dev libx11-dev libxcomposite-dev libxcursor-dev libxinerama-dev libxext-dev libxrandr-dev`
   - Crea una carpeta de build: `mkdir build && cd build`
   - Configura CMake: `cmake ..` (esto descargará JUCE automáticamente en la nube).
   - Compila: `cmake --build .`

¡Feliz programación de audio!
