# Hardware Code ⚡

STM32 / ESP32 嵌入式开发代码归档，集中保存个人硬件实验、外设驱动和通信示例。仓库强调“接线说明 + 固件源码 + 验证步骤”三件套，方便复用和排查问题。

## 内容范围

- STM32 外设、传感器和电机控制实验
- ESP32 网络、摄像头和物联网连接示例
- UART、I²C、SPI、PWM 等常用接口
- 可迁移到 Arduino、PlatformIO 或厂商 IDE 的参考代码

## 建议开发环境

- STM32CubeIDE / Keil（STM32 工程）
- Arduino IDE 或 PlatformIO（ESP32 工程）
- USB 转串口工具与串口监视器

## 使用前检查

1. 确认开发板型号、电源电压和引脚定义。
2. 检查每个示例目录中的接线和依赖说明。
3. 修改 Wi‑Fi、设备密钥等配置时使用本地文件，禁止提交真实凭据。
4. 烧录后先通过串口日志确认启动状态，再连接电机或外设。

## 已提供示例`n`n| 示例 | 说明 |`n| --- | --- |`n| `examples/esp32_blink` | ESP32 板载 LED 心跳灯 |`n| `examples/esp32_wifi_scan` | 扫描附近 Wi‑Fi 并输出信号强度 |`n| `examples/esp32_web_control` | 手机网页控制板载 LED |`n| `examples/stm32_uart_echo` | STM32 HAL 串口回环 |`n`n## 目录建议

```text
stm32/       # STM32 示例
esp32/       # ESP32 示例
docs/        # 接线图、调试记录
examples/    # 最小可运行示例
```

仓库中的 `Blinker_ESP32_CAM` 等目录可能依赖第三方库，请以对应源码注释和板卡文档为准。

## 安全提示

电机、电池和摄像头项目存在电气与机械风险。首次测试请使用限流电源、抬起车轮，并确认急停方式。

## License

MIT License


