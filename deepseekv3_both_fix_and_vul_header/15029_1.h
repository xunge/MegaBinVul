#include <string.h>
#include <strings.h>

#define ENXIO 6
#define SYNTH_TYPE_MIDI 1

struct seq_oss_devinfo {
    int max_synthdev;
    struct {
        int is_midi;
        int midi_mapped;
    } synths[32];
};

struct synth_info {
    int synth_type;
    int synth_subtype;
    int nr_voices;
    int device;
    char name[32];
};

struct midi_info {
    char name[32];
};

struct seq_oss_synth {
    int synth_type;
    int synth_subtype;
    int nr_voices;
    char name[32];
    void *use_lock;
};

extern int snd_seq_oss_midi_make_info(struct seq_oss_devinfo *dp, int midi_mapped, struct midi_info *minf);
extern struct seq_oss_synth *get_synthdev(struct seq_oss_devinfo *dp, int dev);
extern void snd_use_lock_free(void *use_lock);