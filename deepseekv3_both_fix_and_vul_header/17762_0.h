#include <stdio.h>
#include <string.h>

#define JANUS_RTP_EXTMAP_AUDIO_LEVEL "urn:ietf:params:rtp-hdrext:ssrc-audio-level"
#define JANUS_RTP_EXTMAP_VIDEO_ORIENTATION "urn:3gpp:video-orientation"
#define JANUS_RTP_EXTMAP_PLAYOUT_DELAY "http://www.webrtc.org/experiments/rtp-hdrext/playout-delay"
#define JANUS_RTP_EXTMAP_TOFFSET "urn:ietf:params:rtp-hdrext:toffset"
#define JANUS_RTP_EXTMAP_ABS_SEND_TIME "http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time"
#define JANUS_RTP_EXTMAP_TRANSPORT_WIDE_CC "http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01"
#define JANUS_RTP_EXTMAP_MID "urn:ietf:params:rtp-hdrext:sdes:mid"
#define JANUS_RTP_EXTMAP_RID "urn:ietf:params:rtp-hdrext:sdes:rtp-stream-id"
#define JANUS_RTP_EXTMAP_REPAIRED_RID "urn:ietf:params:rtp-hdrext:sdes:repaired-rtp-stream-id"

#define LOG_ERR 3
#define g_snprintf snprintf
#define JANUS_LOG(level, format, ...) fprintf(stderr, format, ##__VA_ARGS__)