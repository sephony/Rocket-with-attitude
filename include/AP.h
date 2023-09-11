#ifndef AP_H_
#define AP_H_
// WiFi
#include <IotWebConf.h>
#include <IotWebConfMultipleWifi.h>
#include <IotWebConfTParameter.h>
#include <IotWebConfUsing.h>

// UpdateServer includes

#include <IotWebConfESP32HTTPUpdateServer.h>
#include <NTPClient.h>

#include "PinConfig.h"
#include "Varibles.h"

using iotwebconf::CheckboxParameter;
using iotwebconf::NumberParameter;
using iotwebconf::ParameterGroup;
using iotwebconf::SelectParameter;
using iotwebconf::TextParameter;

// web config
#define CONFIG_VERSION "dem2"   // Must be short (8 chars max)! Use semantic versioning scheme.
#define CONFIG_PIN GPIO_KEY_AP  // Pin to press to connect AP with default password.
#define STRING_LEN 32           // String length for input elements.
#define NUMBER_LEN 32           // Number length for input elements.

// -- Method declarations.
void handleRoot();
// -- 展示目录
void handleDir();

/* Callback Functions */
// -- WiFi connected callback.
void wifiConnected();
// -- Callback methods.用于在配置保存后执行一些操作
void configSaved();
// -- Callback method placeholders.用于验证Web表单的输入
bool formValidator(iotwebconf::WebRequestWrapper* webRequestWrapper);

extern char RunModeValue[NUMBER_LEN];
extern const char RunModeValues[][STRING_LEN];
extern const char RunModeNames[][STRING_LEN];
extern char ParaMode_Value[NUMBER_LEN];
extern const char LaunchModeValues[][STRING_LEN];
extern const char LaunchModeNames[][STRING_LEN];
extern char LaunchReadyValue[STRING_LEN];

extern char H_ParaValue[NUMBER_LEN];     // 开伞高度
extern char T_ProtectValue[NUMBER_LEN];  // 保护时间
extern char T_DetachValue[NUMBER_LEN];   // 二级点火时间
extern char T_ParaValue[NUMBER_LEN];     // 开伞时间

extern char RGB_BrightnessValue[NUMBER_LEN];  // RGB亮度

extern const char thingName[];  // -- Name of the Thing. Used e.g. as SSID of the own Access Point.
// -- Initial password to connect to the Thing, when it creates an own Access Point.
extern const char wifiInitialApPassword[];

extern WiFiUDP ntpUDP;
extern NTPClient timeClient;
// DNS server
extern DNSServer dnsServer;
// HTTP server
extern HTTPUpdateServer httpUpdater;
// Web server
extern WebServer server;

// Web configuration instance.
extern IotWebConf iotWebConf;

// WiFi 设置链(三组)
extern iotwebconf::ChainedWifiParameterGroup chainedWifiParameterGroups[];

extern iotwebconf::MultipleWifiAddition multipleWifiAddition;

extern iotwebconf::OptionalGroupHtmlFormatProvider optionalGroupHtmlFormatProvider;

// Parameter group.
extern ParameterGroup group_mode;
extern ParameterGroup group_time;
extern ParameterGroup group_heightControl;
extern ParameterGroup group_timeControl;
extern ParameterGroup group_RGB;

// Parameters.
// extern TextParameter FileNameParam;
extern SelectParameter RunMode_Param;
extern SelectParameter ParaMode_Param;
extern CheckboxParameter LaunchReadyParam;

extern iotwebconf::DateTParameter dateParam;
extern iotwebconf::TimeTParameter timeParam;

extern NumberParameter H_ParaParam;
extern NumberParameter T_ProtectParam;
extern NumberParameter T_DetachParam;
extern NumberParameter T_ParaParam;

extern NumberParameter RGB_BrightnessParam;

// extern iotwebconf::TextTParameter<STRING_LEN> FileNameParam;
// extern iotwebconf::FloatTParameter T_DetachParam;
// extern iotwebconf::FloatTParameter T_ParaParam;
// extern iotwebconf::IntTParameter<int16_t> H_ParaParam;
// extern iotwebconf::SelectTParameter<STRING_LEN> RunMode_Param;
// extern iotwebconf::CheckboxTParameter LaunchReadyParam;

#endif /* AP_H_ */
