import XCTest

#if !canImport(ObjectiveC)
public func allTests() -> [XCTestCaseEntry] {
	return [
		testCase(SwiftUnityTexture2DDecoderTests.allTests),
	]
}
#endif
