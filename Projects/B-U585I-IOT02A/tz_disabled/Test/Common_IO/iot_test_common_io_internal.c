/*
 * FreeRTOS Common IO V0.1.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

#include "iot_test_common_io_internal.h"

/* GPIO */
#if defined( IOT_TEST_COMMON_IO_GPIO_SUPPORTED ) && ( IOT_TEST_COMMON_IO_GPIO_SUPPORTED >= 2 )
    void SET_TEST_IOT_GPIO_CONFIG( int testSet )
    {
        /* Test loop calls this for pin i=1 to i=N-1, as the loopback tests need two pins! */
        ltestIotGpioPortA = testSet - 1;
        ltestIotGpioPortB = testSet;

        ustestIotGpioConfig = 1u << 8; /* TEST_DIR_MASK */
    }
#endif

/* UART */
#if defined( IOT_TEST_COMMON_IO_UART_SUPPORTED ) && ( IOT_TEST_COMMON_IO_UART_SUPPORTED >= 1 )
    void SET_TEST_IOT_UART_CONFIG( int testSet )
    {
        uctestIotUartPort = uartTestPort[ testSet ];
    }
#endif

/* SPI */
#if defined( IOT_TEST_COMMON_IO_SPI_SUPPORTED ) && ( IOT_TEST_COMMON_IO_SPI_SUPPORTED >= 1 )
    void SET_TEST_IOT_SPI_CONFIG( int testSet )
    {
        ultestIotSpiInstance = spiTestPort[ testSet ];
        xtestIotSPIDefaultConfigMode = spiIotMode[ testSet ];
        xtestIotSPIDefaultconfigBitOrder = spiIotSpitBitOrder[ testSet ];
        ultestIotSPIFrequency = spiIotFrequency[ testSet ];
        ultestIotSPIDummyValue = spiIotDummyValue[ testSet ];
    }

#endif /* if defined( IOT_TEST_COMMON_IO_SPI_SUPPORTED ) && ( IOT_TEST_COMMON_IO_SPI_SUPPORTED >= 1 ) */
