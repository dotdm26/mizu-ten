################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/Region.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionAS923.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionAU915.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionCN470.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionCN779.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionCommon.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionEU433.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionEU868.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionIN865.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionKR920.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionRU864.c \
C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionUS915.c 

OBJS += \
./Middlewares/LoRaWAN/Mac/Region/Region.o \
./Middlewares/LoRaWAN/Mac/Region/RegionAS923.o \
./Middlewares/LoRaWAN/Mac/Region/RegionAU915.o \
./Middlewares/LoRaWAN/Mac/Region/RegionCN470.o \
./Middlewares/LoRaWAN/Mac/Region/RegionCN779.o \
./Middlewares/LoRaWAN/Mac/Region/RegionCommon.o \
./Middlewares/LoRaWAN/Mac/Region/RegionEU433.o \
./Middlewares/LoRaWAN/Mac/Region/RegionEU868.o \
./Middlewares/LoRaWAN/Mac/Region/RegionIN865.o \
./Middlewares/LoRaWAN/Mac/Region/RegionKR920.o \
./Middlewares/LoRaWAN/Mac/Region/RegionRU864.o \
./Middlewares/LoRaWAN/Mac/Region/RegionUS915.o 

C_DEPS += \
./Middlewares/LoRaWAN/Mac/Region/Region.d \
./Middlewares/LoRaWAN/Mac/Region/RegionAS923.d \
./Middlewares/LoRaWAN/Mac/Region/RegionAU915.d \
./Middlewares/LoRaWAN/Mac/Region/RegionCN470.d \
./Middlewares/LoRaWAN/Mac/Region/RegionCN779.d \
./Middlewares/LoRaWAN/Mac/Region/RegionCommon.d \
./Middlewares/LoRaWAN/Mac/Region/RegionEU433.d \
./Middlewares/LoRaWAN/Mac/Region/RegionEU868.d \
./Middlewares/LoRaWAN/Mac/Region/RegionIN865.d \
./Middlewares/LoRaWAN/Mac/Region/RegionKR920.d \
./Middlewares/LoRaWAN/Mac/Region/RegionRU864.d \
./Middlewares/LoRaWAN/Mac/Region/RegionUS915.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/LoRaWAN/Mac/Region/Region.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/Region.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/Region.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionAS923.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionAS923.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionAS923.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionAU915.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionAU915.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionAU915.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionCN470.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionCN470.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionCN470.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionCN779.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionCN779.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionCN779.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionCommon.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionCommon.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionCommon.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionEU433.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionEU433.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionEU433.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionEU868.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionEU868.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionEU868.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionIN865.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionIN865.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionIN865.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionKR920.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionKR920.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionKR920.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionRU864.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionRU864.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionRU864.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Middlewares/LoRaWAN/Mac/Region/RegionUS915.o: C:/Users/thaid/OneDrive/Desktop/mizu-ten-main/Middlewares/Third_Party/LoRaWAN/Mac/Region/RegionUS915.c Middlewares/LoRaWAN/Mac/Region/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32WL55xx -DCORE_CM4 -DDEBUG -c -I../../Core/Inc -I../../LoRaWAN/App -I../../LoRaWAN/Target -I../../../../../../../Drivers/STM32WLxx_HAL_Driver/Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WLxx/Include -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Crypto -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Mac/Region -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler -I../../../../../../../Middlewares/Third_Party/LoRaWAN/LmHandler/Packages -I../../../../../../../Middlewares/Third_Party/LoRaWAN/Utilities -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy -I../../../../../../../Middlewares/Third_Party/SubGHz_Phy/stm32_radio_driver -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Utilities/misc -I../../../../../../../Utilities/sequencer -I../../../../../../../Utilities/timer -I../../../../../../../Utilities/trace/adv_trace -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/LoRaWAN/Mac/Region/RegionUS915.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-LoRaWAN-2f-Mac-2f-Region

clean-Middlewares-2f-LoRaWAN-2f-Mac-2f-Region:
	-$(RM) ./Middlewares/LoRaWAN/Mac/Region/Region.d ./Middlewares/LoRaWAN/Mac/Region/Region.o ./Middlewares/LoRaWAN/Mac/Region/RegionAS923.d ./Middlewares/LoRaWAN/Mac/Region/RegionAS923.o ./Middlewares/LoRaWAN/Mac/Region/RegionAU915.d ./Middlewares/LoRaWAN/Mac/Region/RegionAU915.o ./Middlewares/LoRaWAN/Mac/Region/RegionCN470.d ./Middlewares/LoRaWAN/Mac/Region/RegionCN470.o ./Middlewares/LoRaWAN/Mac/Region/RegionCN779.d ./Middlewares/LoRaWAN/Mac/Region/RegionCN779.o ./Middlewares/LoRaWAN/Mac/Region/RegionCommon.d ./Middlewares/LoRaWAN/Mac/Region/RegionCommon.o ./Middlewares/LoRaWAN/Mac/Region/RegionEU433.d ./Middlewares/LoRaWAN/Mac/Region/RegionEU433.o ./Middlewares/LoRaWAN/Mac/Region/RegionEU868.d ./Middlewares/LoRaWAN/Mac/Region/RegionEU868.o ./Middlewares/LoRaWAN/Mac/Region/RegionIN865.d ./Middlewares/LoRaWAN/Mac/Region/RegionIN865.o ./Middlewares/LoRaWAN/Mac/Region/RegionKR920.d ./Middlewares/LoRaWAN/Mac/Region/RegionKR920.o ./Middlewares/LoRaWAN/Mac/Region/RegionRU864.d ./Middlewares/LoRaWAN/Mac/Region/RegionRU864.o ./Middlewares/LoRaWAN/Mac/Region/RegionUS915.d ./Middlewares/LoRaWAN/Mac/Region/RegionUS915.o

.PHONY: clean-Middlewares-2f-LoRaWAN-2f-Mac-2f-Region
