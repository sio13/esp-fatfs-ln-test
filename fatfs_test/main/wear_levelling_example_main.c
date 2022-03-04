#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_system.h"

static const char *TAG = "example";

// Handle of the wear levelling library instance
static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;

// Mount path for the partition
const char *base_path = "/spiflash";

void app_main(void)
{
    ESP_LOGI(TAG, "Mounting FAT filesystem");
    // To mount device we need name of device partition, define base_path
    // and allow format partition in case if it is new one and was not formatted before
    const esp_vfs_fat_mount_config_t mount_config = {
            .max_files = 4,
            .format_if_mount_failed = true,
            .allocation_unit_size = CONFIG_WL_SECTOR_SIZE
    };
    esp_err_t err = esp_vfs_fat_spiflash_mount(base_path, "storage", &mount_config, &s_wl_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount FATFS (%s)", esp_err_to_name(err));
        return;
    }

    // Open file for reading
    ESP_LOGI(TAG, "Reading file");
    FILE *f = fopen("/spiflash/longlonglonglong.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    char line[128];
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    char *pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);


    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/diff.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/longlonglonglongg.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/thisisverylongfileyes", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/newdir/normal.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/veryverylongdirnever/normal.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/newdir/normalnotsonormal.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/newdir/normalnotsonormalxy.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);


    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/veryverylongdirnever/normalnormalnormallong.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

    ESP_LOGI(TAG, "Reading file");
    f = fopen("/spiflash/veryverylongdirnever/veryverylongdirnever/longinlonginlong.txt", "rb");
    if (f == NULL) {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    fgets(line, sizeof(line), f);
    fclose(f);
    // strip newline
    pos = strchr(line, '\n');
    if (pos) {
        *pos = '\0';
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);


    // Unmount FATFS
    ESP_LOGI(TAG, "Unmounting FAT filesystem");
    ESP_ERROR_CHECK( esp_vfs_fat_spiflash_unmount(base_path, s_wl_handle));

    ESP_LOGI(TAG, "Done");
}
