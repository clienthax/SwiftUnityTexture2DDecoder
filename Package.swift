// swift-tools-version:5.2
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
	name: "SwiftUnityTexture2DDecoder",
	products: [
		.library(
			name: "SwiftUnityTexture2DDecoder",
			targets: ["SwiftUnityTexture2DDecoder"]
		),
	],
	dependencies: [
	],
	targets: [
		.target(name: "CUnityTexture2DDecoder"),
		.target(
			name: "SwiftUnityTexture2DDecoder",
			dependencies: ["CUnityTexture2DDecoder"]
		),
		.testTarget(
			name: "SwiftUnityTexture2DDecoderTests",
			dependencies: ["SwiftUnityTexture2DDecoder"]),
	],
	cxxLanguageStandard: .cxx11
)
