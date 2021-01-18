#include "include/exports.h"

#include "bcn.h"
#include "pvrtc.h"
#include "etc.h"
#include "atc.h"
#include "astc.h"
#include "crunch.h"
#include "unitycrunch.h"

bool DecodeDXT1(const void* data, long width, long height, void* image)
{
	return decode_bc1(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeDXT5(const void* data, long width, long height, void* image)
{
	return decode_bc3(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodePVRTC(const void* data, long width, long height, void* image, bool is2bpp)
{
	return decode_pvrtc(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image), is2bpp ? 1 : 0);
}

bool DecodeETC1(const void* data, long width, long height, void* image)
{
	return decode_etc1(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeETC2(const void* data, long width, long height, void* image)
{
	return decode_etc2(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeETC2A1(const void* data, long width, long height, void* image)
{
	return decode_etc2a1(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeETC2A8(const void* data, long width, long height, void* image)
{
	return decode_etc2a8(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeEACR(const void* data, long width, long height, void* image)
{
	return decode_eacr(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeEACRSigned(const void* data, long width, long height, void* image)
{
	return decode_eacr_signed(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeEACRG(const void* data, long width, long height, void* image)
{
	return decode_eacrg(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeEACRGSigned(const void* data, long width, long height, void* image)
{
	return decode_eacrg_signed(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeBC4(const void* data, long width, long height, void* image)
{
	return decode_bc4(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeBC5(const void* data, long width, long height, void* image)
{
	return decode_bc5(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeBC6(const void* data, long width, long height, void* image)
{
	return decode_bc6(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeBC7(const void* data, long width, long height, void* image)
{
	return decode_bc7(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeATCRGB4(const void* data, long width, long height, void* image)
{
	return decode_atc_rgb4(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeATCRGBA8(const void* data, long width, long height, void* image)
{
	return decode_atc_rgba8(static_cast<const uint8_t*>(data), width, height, static_cast<uint32_t*>(image));
}

bool DecodeASTC(const void* data, long width, long height, long blockWidth, long blockHeight, void* image)
{
	return decode_astc(static_cast<const uint8_t*>(data), width, height, blockWidth, blockHeight, static_cast<uint32_t*>(image));
}

void DisposeBuffer(void** ppBuffer)
{
	if (ppBuffer == nullptr)
	{
		return;
	}

	auto ppTypedBuffer = reinterpret_cast<uint8_t**>(ppBuffer);

	delete[](*ppTypedBuffer);

	*ppBuffer = nullptr;
}

void UnpackCrunch(const void* data, uint32_t dataSize, void** ppResult, uint32_t* pResultSize)
{
	void* result;
	uint32_t resultSize;

	if (ppResult != nullptr)
	{
		*ppResult = nullptr;
	}

	if (pResultSize != nullptr)
	{
		*pResultSize = 0;
	}

	if (!crunch_unpack_level(static_cast<const uint8_t*>(data), dataSize, 0, &result, &resultSize)) {
		return;
	}

	if (ppResult != nullptr)
	{
		*ppResult = result;
	}

	if (pResultSize != nullptr)
	{
		*pResultSize = resultSize;
	}
}

void UnpackUnityCrunch(const void* data, uint32_t dataSize, void** ppResult, uint32_t* pResultSize)
{
	void* result;
	uint32_t resultSize;

	if (ppResult != nullptr)
	{
		*ppResult = nullptr;
	}

	if (pResultSize != nullptr)
	{
		*pResultSize = 0;
	}

	if (!unity_crunch_unpack_level(static_cast<const uint8_t*>(data), dataSize, 0, &result, &resultSize)) {
		return;
	}

	if (ppResult != nullptr)
	{
		*ppResult = result;
	}

	if (pResultSize != nullptr)
	{
		*pResultSize = resultSize;
	}
}
