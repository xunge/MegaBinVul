#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void* jack_client_t;
typedef void* jack_port_t;

typedef enum {
    JackNullOption = 0,
    JackServerStarted = 1,
    JackServerFailed = 2
} jack_options_t;

typedef unsigned int jack_status_t;

#define JACK_DEFAULT_MIDI_TYPE "midi"
#define JACK_DEFAULT_AUDIO_TYPE "audio"
#define JackPortIsInput 1
#define JackPortIsOutput 2

typedef struct {
    int activated;
    jack_client_t *jack_client;
    jack_port_t **jack_in_ports;
    jack_port_t **jack_out_ports;
    jack_port_t *jack_midiin_port;
    jack_port_t *jack_midiout_port;
    struct PyoJackMidiEvent *midi_events;
    int midi_event_count;
} PyoJackBackendData;

typedef struct PyoJackMidiEvent {
    long timestamp;
} PyoJackMidiEvent;

typedef struct Server {
    void *audio_be_data;
    char serverName[32];
    int duplex;
    int ichnls;
    int input_offset;
    int nchnls;
    int output_offset;
    int withJackMidi;
    double samplingRate;
    int bufferSize;
    int isJackTransportSlave;
} Server;

#define Py_BEGIN_ALLOW_THREADS
#define Py_END_ALLOW_THREADS

void *PyMem_RawMalloc(size_t size);
void *PyMem_RawCalloc(size_t nelem, size_t elsize);

void Server_error(Server *self, const char *msg);
void Server_debug(Server *self, const char *msg, ...);
void Server_warning(Server *self, const char *msg, ...);
void Server_jack_autoconnect(Server *self);

jack_client_t *jack_client_open(const char *client_name, jack_options_t options, jack_status_t *status, const char *server_name);
int jack_get_sample_rate(jack_client_t *client);
int jack_get_buffer_size(jack_client_t *client);
const char *jack_get_client_name(jack_client_t *client);
int jack_client_close(jack_client_t *client);
jack_port_t *jack_port_register(jack_client_t *client, const char *port_name, const char *port_type, unsigned long flags, unsigned long buffer_size);
int jack_activate(jack_client_t *client);

void jack_set_error_function(void (*func)(const char *));
int jack_set_sample_rate_callback(jack_client_t *client, int (*srate_cb)(unsigned int nframes, void *arg), void *arg);
void jack_on_shutdown(jack_client_t *client, void (*shutdown_cb)(void *arg), void *arg);
int jack_set_buffer_size_callback(jack_client_t *client, int (*bufsize_cb)(unsigned int nframes, void *arg), void *arg);
int jack_set_process_callback(jack_client_t *client, int (*process_cb)(unsigned int nframes, void *arg), void *arg);
int jack_set_sync_callback(jack_client_t *client, int (*sync_cb)(unsigned int state, void *arg), void *arg);

void jack_error_cb(const char *desc);
int jack_srate_cb(unsigned int nframes, void *arg);
void jack_shutdown_cb(void *arg);
int jack_bufsize_cb(unsigned int nframes, void *arg);
int jack_callback(unsigned int nframes, void *arg);
int jack_transport_cb(unsigned int state, void *arg);