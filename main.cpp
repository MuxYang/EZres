/*
 * EZres - Screen Resolution and Scaling Management Tool
 * Copyright (C) 2024 [Mux_Yang]
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Language support
enum class Language { EN, ZH };

class I18n {
private:
    Language lang;
    
    static bool IsChineseSystem() {
        LANGID langId = GetUserDefaultUILanguage();
        WORD primaryLang = PRIMARYLANGID(langId);
        return primaryLang == LANG_CHINESE;
    }
    
public:
    I18n() {
        lang = IsChineseSystem() ? Language::ZH : Language::EN;
    }
    
    // Messages for resolution operations
    std::string currentResolution() const {
        return lang == Language::ZH ? "当前分辨率: " : "Current resolution: ";
    }
    
    std::string availableResolutions() const {
        return lang == Language::ZH ? "可用分辨率:" : "Available resolutions:";
    }
    
    std::string settingResolution() const {
        return lang == Language::ZH ? "正在设置分辨率为 " : "Setting resolution to ";
    }
    
    std::string resolutionSuccess() const {
        return lang == Language::ZH ? "分辨率设置成功！" : "Resolution set successfully!";
    }
    
    std::string resolutionFailed() const {
        return lang == Language::ZH ? "分辨率设置失败！" : "Failed to set resolution!";
    }
    
    std::string resolutionNotSupported() const {
        return lang == Language::ZH ? 
            "错误：不支持的分辨率。请使用 -a 参数查看可用分辨率列表。" :
            "Error: Unsupported resolution. Use -a to see available resolutions.";
    }
    
    std::string resolutionWithRefreshNotSupported() const {
        return lang == Language::ZH ?
            "错误：不支持该分辨率和刷新率的组合。请使用 -a 参数查看可用分辨率列表。" :
            "Error: Unsupported resolution and refresh rate combination. Use -a to see available resolutions.";
    }
    
    std::string invalidNumber() const {
        return lang == Language::ZH ?
            "错误：无效的数字参数。" :
            "Error: Invalid numeric argument.";
    }
    
    std::string invalidResolutionValues() const {
        return lang == Language::ZH ?
            "错误：分辨率和刷新率必须为正数。" :
            "Error: Resolution and refresh rate must be positive numbers.";
    }
    
    // Messages for scaling operations
    std::string scalingRange() const {
        return lang == Language::ZH ? 
            "缩放比例必须在100%-500%之间" : 
            "Scaling percentage must be between 100% and 500%";
    }
    
    std::string settingScaling() const {
        return lang == Language::ZH ? "正在设置缩放比例为 " : "Setting scaling to ";
    }
    
    std::string scalingSuccess() const {
        return lang == Language::ZH ? 
            "缩放比例设置成功！请注销并重新登录以完全生效。" :
            "Scaling set successfully! Please log out and log back in for full effect.";
    }
    
    std::string scalingFailed() const {
        return lang == Language::ZH ? "缩放比例设置失败！" : "Failed to set scaling!";
    }
    
    // Error messages
    std::string invalidCommand() const {
        return lang == Language::ZH ? "无效的命令行参数！" : "Invalid command line arguments!";
    }
    
    // Usage messages
    std::string usage() const {
        return lang == Language::ZH ? "用法:" : "Usage:";
    }
    
    std::string usageResolution() const {
        return lang == Language::ZH ?
            "  EZres.exe -r <宽度> <高度> [刷新率]  - 设置分辨率" :
            "  EZres.exe -r <width> <height> [refresh]  - Set resolution";
    }
    
    std::string usageForce() const {
        return lang == Language::ZH ?
            "  EZres.exe -f -r <宽度> <高度> [刷新率] - 强制设置分辨率（跳过验证）" :
            "  EZres.exe -f -r <width> <height> [refresh] - Force set resolution (skip validation)";
    }
    
    std::string forceWarning() const {
        return lang == Language::ZH ?
            "警告：正在强制设置分辨率，跳过验证..." :
            "Warning: Force setting resolution, skipping validation...";
    }
    
    std::string usageScaling() const {
        return lang == Language::ZH ?
            "  EZres.exe -s <百分比>              - 设置缩放比例 (100-500)" :
            "  EZres.exe -s <percentage>          - Set scaling (100-500)";
    }
    
    std::string usageList() const {
        return lang == Language::ZH ?
            "  EZres.exe -l                       - 显示当前设置" :
            "  EZres.exe -l                       - Show current settings";
    }
    
    std::string usageAll() const {
        return lang == Language::ZH ?
            "  EZres.exe -a                       - 显示所有可用分辨率" :
            "  EZres.exe -a                       - Show all available resolutions";
    }
    
    std::string usageHelp() const {
        return lang == Language::ZH ?
            "  EZres.exe -h                       - 显示帮助" :
            "  EZres.exe -h                       - Show help";
    }
    
    std::string examples() const {
        return lang == Language::ZH ? "示例:" : "Examples:";
    }
    
    std::string example1() const {
        return lang == Language::ZH ?
            "  EZres.exe -r 1920 1080             - 设置为1920x1080" :
            "  EZres.exe -r 1920 1080             - Set to 1920x1080";
    }
    
    std::string example2() const {
        return lang == Language::ZH ?
            "  EZres.exe -r 1920 1080 60          - 设置为1920x1080@60Hz" :
            "  EZres.exe -r 1920 1080 60          - Set to 1920x1080@60Hz";
    }
    
    std::string example3() const {
        return lang == Language::ZH ?
            "  EZres.exe -s 125                   - 设置缩放为125%" :
            "  EZres.exe -s 125                   - Set scaling to 125%";
    }
    
    std::string example4() const {
        return lang == Language::ZH ?
            "  EZres.exe -f -r 1920 1080          - 强制设置为1920x1080" :
            "  EZres.exe -f -r 1920 1080          - Force set to 1920x1080";
    }
};

// Global i18n instance
static I18n i18n;

class DisplayManager {
private:
    static bool SetDPIScaling(int percentage) {
        HKEY hKey;
        LONG result = RegOpenKeyExW(HKEY_CURRENT_USER, 
            L"Control Panel\\Desktop", 0, KEY_SET_VALUE, &hKey);
        
        if (result != ERROR_SUCCESS) {
            return false;
        }

        // Calculate DPI value (96 DPI = 100%)
        int dpiValue = (96 * percentage) / 100;
        std::wstring dpiStr = std::to_wstring(dpiValue);
        
        result = RegSetValueExW(hKey, L"LogPixels", 0, REG_DWORD, 
            (BYTE*)&dpiValue, sizeof(dpiValue));
        
        RegCloseKey(hKey);
        
        if (result == ERROR_SUCCESS) {
            // Notify system that DPI has changed
            SendMessageW(HWND_BROADCAST, WM_SETTINGCHANGE, 
                SPI_SETLOGICALDPIOVERRIDE, 0);
            return true;
        }
        return false;
    }
    
public:
    // Validation result enum
    enum class ValidationResult {
        VALID,
        RESOLUTION_NOT_SUPPORTED,
        REFRESH_RATE_NOT_SUPPORTED
    };
    
    // Validate resolution before changing
    static ValidationResult ValidateResolution(int width, int height, int refreshRate = 0) {
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        bool resolutionExists = false;
        bool refreshRateExists = false;
        
        for (int i = 0; EnumDisplaySettings(NULL, i, &devMode); i++) {
            if (devMode.dmPelsWidth == (DWORD)width && 
                devMode.dmPelsHeight == (DWORD)height) {
                resolutionExists = true;
                if (refreshRate <= 0 || devMode.dmDisplayFrequency == (DWORD)refreshRate) {
                    refreshRateExists = true;
                    break;
                }
            }
        }
        
        if (!resolutionExists) {
            return ValidationResult::RESOLUTION_NOT_SUPPORTED;
        }
        if (refreshRate > 0 && !refreshRateExists) {
            return ValidationResult::REFRESH_RATE_NOT_SUPPORTED;
        }
        return ValidationResult::VALID;
    }

    static bool ChangeResolution(int width, int height, int refreshRate = 0) {
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        if (!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
            return false;
        }
        
        devMode.dmPelsWidth = width;
        devMode.dmPelsHeight = height;
        devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
        
        if (refreshRate > 0) {
            devMode.dmDisplayFrequency = refreshRate;
            devMode.dmFields |= DM_DISPLAYFREQUENCY;
        }
        
        LONG result = ChangeDisplaySettings(&devMode, CDS_UPDATEREGISTRY);
        return (result == DISP_CHANGE_SUCCESSFUL);
    }
    
    static bool SetScaling(int percentage) {
        if (percentage < 100 || percentage > 500) {
            std::cout << i18n.scalingRange() << std::endl;
            return false;
        }
        
        return SetDPIScaling(percentage);
    }
    
    static void ListCurrentSettings() {
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
            std::cout << i18n.currentResolution() << devMode.dmPelsWidth 
                      << "x" << devMode.dmPelsHeight;
            if (devMode.dmDisplayFrequency > 0) {
                std::cout << " @" << devMode.dmDisplayFrequency << "Hz";
            }
            std::cout << std::endl;
        }
    }
    
    static void ListAvailableResolutions() {
        std::cout << i18n.availableResolutions() << std::endl;
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        
        for (int i = 0; EnumDisplaySettings(NULL, i, &devMode); i++) {
            std::cout << devMode.dmPelsWidth << "x" << devMode.dmPelsHeight;
            if (devMode.dmDisplayFrequency > 0) {
                std::cout << " @" << devMode.dmDisplayFrequency << "Hz";
            }
            std::cout << std::endl;
        }
    }
};

void ShowUsage() {
    std::cout << i18n.usage() << std::endl;
    std::cout << i18n.usageResolution() << std::endl;
    std::cout << i18n.usageForce() << std::endl;
    std::cout << i18n.usageScaling() << std::endl;
    std::cout << i18n.usageList() << std::endl;
    std::cout << i18n.usageAll() << std::endl;
    std::cout << i18n.usageHelp() << std::endl;
    std::cout << std::endl;
    std::cout << i18n.examples() << std::endl;
    std::cout << i18n.example1() << std::endl;
    std::cout << i18n.example2() << std::endl;
    std::cout << i18n.example3() << std::endl;
    std::cout << i18n.example4() << std::endl;
}

int main(int argc, char* argv[]) {
    // Set console code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    if (argc < 2) {
        ShowUsage();
        return 1;
    }
    
    std::string command = argv[1];
    
    // Check for force flag
    bool forceMode = false;
    int argOffset = 0;
    if (command == "-f" && argc >= 3) {
        forceMode = true;
        command = argv[2];
        argOffset = 1;
    }
    
    if (command == "-h" || command == "--help") {
        ShowUsage();
        return 0;
    }
    else if (command == "-l") {
        DisplayManager::ListCurrentSettings();
        return 0;
    }
    else if (command == "-a") {
        DisplayManager::ListAvailableResolutions();
        return 0;
    }
    else if (command == "-r" && argc >= (4 + argOffset)) {
        int width, height, refreshRate;
        try {
            width = std::stoi(argv[2 + argOffset]);
            height = std::stoi(argv[3 + argOffset]);
            refreshRate = (argc >= (5 + argOffset)) ? std::stoi(argv[4 + argOffset]) : 0;
        } catch (const std::exception&) {
            std::cout << i18n.invalidNumber() << std::endl;
            return 1;
        }
        
        // Validate that values are positive
        if (width <= 0 || height <= 0 || refreshRate < 0) {
            std::cout << i18n.invalidResolutionValues() << std::endl;
            return 1;
        }
        
        // Validate the resolution before attempting to change (unless force mode)
        if (!forceMode) {
            auto validationResult = DisplayManager::ValidateResolution(width, height, refreshRate);
            if (validationResult != DisplayManager::ValidationResult::VALID) {
                if (validationResult == DisplayManager::ValidationResult::RESOLUTION_NOT_SUPPORTED) {
                    std::cout << i18n.resolutionNotSupported() << std::endl;
                } else {
                    std::cout << i18n.resolutionWithRefreshNotSupported() << std::endl;
                }
                return 1;
            }
        } else {
            std::cout << i18n.forceWarning() << std::endl;
        }
        
        std::cout << i18n.settingResolution() << width << "x" << height;
        if (refreshRate > 0) {
            std::cout << "@" << refreshRate << "Hz";
        }
        std::cout << "..." << std::endl;
        
        if (DisplayManager::ChangeResolution(width, height, refreshRate)) {
            std::cout << i18n.resolutionSuccess() << std::endl;
            return 0;
        } else {
            std::cout << i18n.resolutionFailed() << std::endl;
            return 1;
        }
    }
    else if (command == "-s" && argc >= (3 + argOffset)) {
        int percentage;
        try {
            percentage = std::stoi(argv[2 + argOffset]);
        } catch (const std::exception&) {
            std::cout << i18n.invalidNumber() << std::endl;
            return 1;
        }
        
        std::cout << i18n.settingScaling() << percentage << "%..." << std::endl;
        
        if (DisplayManager::SetScaling(percentage)) {
            std::cout << i18n.scalingSuccess() << std::endl;
            return 0;
        } else {
            std::cout << i18n.scalingFailed() << std::endl;
            return 1;
        }
    }
    else {
        std::cout << i18n.invalidCommand() << std::endl;
        ShowUsage();
        return 1;
    }
}
