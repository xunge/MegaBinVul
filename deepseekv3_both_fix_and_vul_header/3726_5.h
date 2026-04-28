#include <string>
#include <memory>
#include <iostream>
#include <functional>

#define CHECK(condition) if (!(condition)) std::cerr

enum LoadType {
  LoadTypeURL,
  LoadTypeMediaSource,
  LoadTypeMediaStream
};

enum CORSMode {
  CORSModeUnspecified,
  CORSModeAnonymous,
  CORSModeUseCredentials
};

enum MediaPlayerType {
  MEDIA_PLAYER_TYPE_URL,
  MEDIA_PLAYER_TYPE_MEDIA_SOURCE,
  MEDIA_PLAYER_TYPE_MEDIA_STREAM
};

class GURL {
};

class blink {
public:
  class WebURL {
  };
  class WebDocument {
  public:
    GURL firstPartyForCookies();
  };
  class WebFrame {
  public:
    blink::WebDocument document();
  };
};

class WebMediaPlayer {
public:
  enum NetworkState {
    NetworkStateLoading
  };
  enum ReadyState {
    ReadyStateHaveNothing
  };
};

class RenderThreadImpl {
public:
  static RenderThreadImpl* current();
  class RendererDemuxerAndroid* renderer_demuxer();
};

class RendererDemuxerAndroid {
public:
  int GetNextDemuxerClientID();
};

class MediaSourceDelegate {
public:
  MediaSourceDelegate(RendererDemuxerAndroid*, int, void*, void*);
  void InitializeMediaSource(std::function<void()>, std::function<void()>, 
                           std::function<void()>, std::function<void()>, 
                           std::function<void()>);
};

class MediaInfoLoader {
public:
  MediaInfoLoader(const blink::WebURL&, CORSMode, std::function<void()>);
  void set_single_origin(bool);
  void Start(blink::WebFrame*);
};

class PlayerManager {
public:
  void Initialize(MediaPlayerType, int, const blink::WebURL&, const GURL&, int);
  bool ShouldEnterFullscreen(blink::WebFrame*);
  void EnterFullscreen(int, blink::WebFrame*);
};

class WebMediaPlayerAndroid {
public:
  void load(LoadType load_type, const blink::WebURL& url, CORSMode cors_mode);
  void SetDecryptorReadyCB();
  void OnMediaSourceOpened();
  void OnNeedKey();
  void UpdateNetworkState(WebMediaPlayer::NetworkState);
  void OnDurationChanged();
  void DidLoadMediaInfo();
  void UpdateReadyState(WebMediaPlayer::ReadyState);
  
  MediaPlayerType player_type_;
  bool has_media_metadata_;
  bool has_media_info_;
  std::unique_ptr<MediaSourceDelegate> media_source_delegate_;
  std::unique_ptr<MediaInfoLoader> info_loader_;
  blink::WebURL url_;
  blink::WebFrame* frame_;
  PlayerManager* manager_;
  int player_id_;
  void* media_loop_;
  void* media_log_;
  struct WeakPtr {
    void* GetWeakPtr();
  } weak_factory_;
};

namespace media {
  typedef std::function<void()> SetDecryptorReadyCB;
  SetDecryptorReadyCB BindToCurrentLoop(std::function<void()>);
}

namespace base {
  template<typename T, typename... Args>
  std::function<void()> Bind(void (T::*)(Args...), void*);
}