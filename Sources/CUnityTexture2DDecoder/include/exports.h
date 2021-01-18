#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

bool DecodeDXT1(const void* data, long width, long height, void* image);
bool DecodeDXT5(const void* data, long width, long height, void* image);
bool DecodePVRTC(const void* data, long width, long height, void* image, bool is2bpp);
bool DecodeETC1(const void* data, long width, long height, void* image);
bool DecodeETC2(const void* data, long width, long height, void* image);
bool DecodeETC2A1(const void* data, long width, long height, void* image);
bool DecodeETC2A8(const void* data, long width, long height, void* image);
bool DecodeEACR(const void* data, long width, long height, void* image);
bool DecodeEACRSigned(const void* data, long width, long height, void* image);
bool DecodeEACRG(const void* data, long width, long height, void* image);
bool DecodeEACRGSigned(const void* data, long width, long height, void* image);
bool DecodeBC4(const void* data, long width, long height, void* image);
bool DecodeBC5(const void* data, long width, long height, void* image);
bool DecodeBC6(const void* data, long width, long height, void* image);
bool DecodeBC7(const void* data, long width, long height, void* image);
bool DecodeATCRGB4(const void* data, long width, long height, void* image);
bool DecodeATCRGBA8(const void* data, long width, long height, void* image);
bool DecodeASTC(const void* data, long width, long height, long blockWidth, long blockHeight, void* image);
void DisposeBuffer(void** ppBuffer);
void UnpackCrunch(const void* data, uint32_t dataSize, void** ppResult, uint32_t* pResultSize);
void UnpackUnityCrunch(const void* data, uint32_t dataSize, void** ppResult, uint32_t* pResultSize);

#ifdef __cplusplus
}
#endif
