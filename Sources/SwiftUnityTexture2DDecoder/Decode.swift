import CUnityTexture2DDecoder

@inlinable
public func decodeUnityTexture2D(_ data: UnsafeRawPointer, format: TextureFormat, width: Int32, height: Int32, into output: UnsafeMutableRawPointer) -> Bool {
	switch format {
	case .dxt1:
		return DecodeDXT1(data, width, height, output)
	case .dxt5:
		return DecodeDXT5(data, width, height, output)
	case .bc4:
		return DecodeBC4(data, width, height, output)
	case .bc5:
		return DecodeBC5(data, width, height, output)
	case .bc6h:
		return DecodeBC6(data, width, height, output)
	case .bc7:
		return DecodeBC7(data, width, height, output)
	case .pvrtc_rgb2, .pvrtc_rgba2:
		return DecodePVRTC(data, width, height, output, true)
	case .pvrtc_rgb4, .pvrtc_rgba4:
		return DecodePVRTC(data, width, height, output, false)
	case .etc_rgb4, .etc_rgb4_3ds:
		return DecodeETC1(data, width, height, output)
	case .atc_rgb4:
		return DecodeATCRGB4(data, width, height, output)
	case .atc_rgba8:
		return DecodeATCRGBA8(data, width, height, output)
	case .eac_r:
		return DecodeEACR(data, width, height, output)
	case .eac_r_signed:
		return DecodeEACRSigned(data, width, height, output)
	case .eac_rg:
		return DecodeEACRG(data, width, height, output)
	case .eac_rg_signed:
		return DecodeEACRGSigned(data, width, height, output)
	case .etc2_rgb:
		return DecodeETC2(data, width, height, output)
	case .etc2_rgba1:
		return DecodeETC2A1(data, width, height, output)
	case .etc2_rgba8, .etc_rgba8_3ds:
		return DecodeETC2A8(data, width, height, output)
	case .astc_rgb_4x4, .astc_rgba_4x4, .astc_hdr_4x4:
		return DecodeASTC(data, width, height, 4, 4, output)
	case .astc_rgb_5x5, .astc_rgba_5x5, .astc_hdr_5x5:
		return DecodeASTC(data, width, height, 5, 5, output)
	case .astc_rgb_6x6, .astc_rgba_6x6, .astc_hdr_6x6:
		return DecodeASTC(data, width, height, 6, 6, output)
	case .astc_rgb_8x8, .astc_rgba_8x8, .astc_hdr_8x8:
		return DecodeASTC(data, width, height, 8, 8, output)
	case .astc_rgb_10x10, .astc_rgba_10x10, .astc_hdr_10x10:
		return DecodeASTC(data, width, height, 10, 10, output)
	case .astc_rgb_12x12, .astc_rgba_12x12, .astc_hdr_12x12:
		return DecodeASTC(data, width, height, 12, 12, output)
	default:
		return false
	}
}

@inlinable
public func decodeUnityTexture2D(_ data: [UInt8], format: TextureFormat, width: Int32, height: Int32) -> [UInt8]? {
	if width == 0 && height == 0 {
		return []
	}
	let out = [UInt8](unsafeUninitializedCapacity: Int(width * height)) { (outPtr, len) in
		data.withUnsafeBytes { inPtr in
			if decodeUnityTexture2D(inPtr.baseAddress!, format: format, width: width, height: height, into: outPtr.baseAddress!) {
				len = Int(width * height) * 4
			} else {
				len = 0
			}
		}
	}
	if out.isEmpty {
		return nil
	}
	return out
}
