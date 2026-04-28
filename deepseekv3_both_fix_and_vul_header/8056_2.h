class FontDescription {};
class FontFallbackList {};

class Font {
public:
    Font(const Font& other);
    
private:
    FontDescription m_fontDescription;
    FontFallbackList m_fontFallbackList;
    int m_canShapeWordByWord;
    int m_shapeWordByWordComputed;
};