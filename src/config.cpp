#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <windows.h>

// Configuration structure
struct Config {
    bool aimbotEnabled;
    bool espEnabled;
    float circleRadius;
    float velocityMultiplier;
    int keybindAimbot;
    int keybindESP;
    int keybindMenu;
};

// Global configuration
Config globalConfig = {
    false,
    false,
    50.0f,
    1.0f,
    VK_RSHIFT,
    VK_LCTRL,
    VK_INSERT
};

const char* CONFIG_FILE = "niell_config.ini";

void SaveConfig() {
    std::ofstream configFile(CONFIG_FILE);
    if (configFile.is_open()) {
        configFile << "[AIMBOT]\n";
        configFile << "enabled=" << (globalConfig.aimbotEnabled ? "1" : "0") << "\n";
        configFile << "circle_radius=" << globalConfig.circleRadius << "\n";
        configFile << "[ESP]\n";
        configFile << "enabled=" << (globalConfig.espEnabled ? "1" : "0") << "\n";
        configFile << "[GAMEPLAY]\n";
        configFile << "velocity_multiplier=" << globalConfig.velocityMultiplier << "\n";
        configFile.close();
    }
}

void LoadConfig() {
    std::ifstream configFile(CONFIG_FILE);
    if (configFile.is_open()) {
        std::string line;
        while (std::getline(configFile, line)) {
            if (line.find("circle_radius=") != std::string::npos) {
                globalConfig.circleRadius = std::stof(line.substr(line.find('=') + 1));
            }
        }
        configFile.close();
    }
}

extern "C" {
    __declspec(dllexport) void InitializeConfig() { LoadConfig(); }
    __declspec(dllexport) void UpdateConfig() { SaveConfig(); }
}