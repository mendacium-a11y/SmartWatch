#include <zephyr.h>
#include <device.h>
#include <drivers/uart.h>
#include <net/net_if.h>
#include <net/net_ip.h>
#include <net/http/server.h>
#include <wifi.h>

// Wi-Fi Credentials
#define WIFI_SSID "your-ssid"
#define WIFI_PASSWORD "your-password"

// Define UART device names (for GPS and serial communication)
#define GPS_UART_LABEL "UART_2"
#define HEART_RATE_UART_LABEL "UART_3"

const struct device *gps_uart;
const struct device *heart_rate_uart;
static struct net_if *iface;

// HTTP Server
static struct http_server_ctx http_ctx;

// GPS Data Buffer
static char gps_data_buffer[256];

// Heart Rate Data
float heart_rate = 0.0;

// Wi-Fi Connection Function
void wifi_connect(void) {
    struct wifi_connect_req_params params = {
        .ssid = WIFI_SSID,
        .ssid_length = strlen(WIFI_SSID),
        .psk = WIFI_PASSWORD,
        .psk_length = strlen(WIFI_PASSWORD),
        .security = WIFI_SECURITY_TYPE_PSK
    };
    
    if (wifi_connect(iface, &params) == 0) {
        printk("Connected to WiFi\n");
    } else {
        printk("Failed to connect to WiFi\n");
    }
}

// GPS Data Handler (parses and updates GPS coordinates)
void parse_gps_data(char *data) {
    // Example NMEA sentence parsing for latitude and longitude
    // Implement basic parsing for "$GPRMC" or "$GPGGA" NMEA sentences
}

// HTTP Handlers
static int root_handler(const struct http_request *req, struct http_response *rsp) {
    rsp->content_type = "text/html";
    rsp->body = "<h1>Hello, World!</h1>";
    rsp->body_len = strlen(rsp->body);
    return 0;
}

static int heartrate_handler(const struct http_request *req, struct http_response *rsp) {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "Heart Rate: %.2f bpm", heart_rate);
    rsp->content_type = "text/plain";
    rsp->body = buffer;
    rsp->body_len = strlen(buffer);
    return 0;
}

static int gps_handler(const struct http_request *req, struct http_response *rsp) {
    rsp->content_type = "text/plain";
    rsp->body = gps_data_buffer;
    rsp->body_len = strlen(gps_data_buffer);
    return 0;
}

void setup_http_server(void) {
    http_server_init(&http_ctx, NULL, 80);
    http_add_route(&http_ctx, "/", HTTP_GET, root_handler);
    http_add_route(&http_ctx, "/heartrate", HTTP_GET, heartrate_handler);
    http_add_route(&http_ctx, "/gps", HTTP_GET, gps_handler);
    http_server_start(&http_ctx);
    printk("HTTP server started on port 80\n");
}

void main(void) {
    printk("Starting Zephyr application...\n");

    // Initialize Wi-Fi and HTTP server
    iface = net_if_get_default();
    wifi_connect();
    setup_http_server();

    // Initialize GPS UART
    gps_uart = device_get_binding(GPS_UART_LABEL);
    if (!gps_uart) {
        printk("GPS UART device not found\n");
    }

    // Initialize Heart Rate UART
    heart_rate_uart = device_get_binding(HEART_RATE_UART_LABEL);
    if (!heart_rate_uart) {
        printk("Heart Rate UART device not found\n");
    }

    // Main loop
    while (1) {
        // Poll GPS data
        int recv_len = uart_fifo_read(gps_uart, gps_data_buffer, sizeof(gps_data_buffer));
        if (recv_len > 0) {
            gps_data_buffer[recv_len] = '\0';
            parse_gps_data(gps_data_buffer);  // Custom function for parsing GPS
        }

        // Poll Heart Rate Sensor data here (you need to implement reading from MAX30100)

        k_sleep(K_SECONDS(1));
    }
}
