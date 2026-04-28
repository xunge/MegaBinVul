typedef struct CFF_Face_* CFF_Face;
typedef struct FT_Service_MetricsVariations_ {
    void (*metrics_adjust)(void*);
} *FT_Service_MetricsVariations;
typedef struct FT_FaceRec_* FT_Face;

struct CFF_Face_ {
    void* tt_var;
    void* var;
};

#define FT_FACE(face) ((FT_Face)(face))