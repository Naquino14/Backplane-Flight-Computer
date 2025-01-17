/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/sensor.h>
#include <app_version.h>
#include <zephyr/logging/log.h>
#include <zephyr/net/socket.h>



#define SLEEP_TIME_MS   1000

LOG_MODULE_REGISTER(main, CONFIG_APP_LOG_LEVEL);

K_QUEUE_DEFINE(lora_tx_queue);
K_QUEUE_DEFINE(net_tx_queue);

static void network_init() {

}


static void init(void) {
    // Queues
    k_queue_init(&lora_tx_queue);
    k_queue_init(&net_tx_queue);

    // Devices
    const struct device *const sx1276 = DEVICE_DT_GET_ONE(semtech_sx1276);
    if (!device_is_ready(sx1276)) {
        printk("Device %s is not ready.\n", sx1276->name);
    }

    const struct device *const wiznet = DEVICE_DT_GET_ONE(wiznet_w5500);
    if (!device_is_ready(wiznet)) {
        printk("Device %s is not ready.\n", wiznet->name);
    }

    network_init();
}

static void get_gnss(void) {

}


static void lora_tx() {
    if (!k_queue_is_empty(&lora_tx_queue)) {


    }
}

static void wiznet_tx() {

}

int main() {
    init();




    return 0;
}