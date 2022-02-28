//
//  Device.swift
//  Zebra
//
//  Created by Adam Demasi on 8/2/2022.
//  Copyright © 2022 Zebra Team. All rights reserved.
//

import UIKit

fileprivate let isSimulated = SlingshotController.isSimulated

@objc(ZBDevice)
class Device: NSObject {

	// MARK: - Environment

	@objc static let path: String = {
		// Construct a safe PATH. This will be set app-wide.
		// There is some commented code here for Procursus prefixed “rootless” bootstrap in future.
//		let prefix = URL(fileURLWithPath: "/", isDirectory: true)
		let path = ["/usr/sbin", "/usr/bin", "/sbin", "/bin"]
//		if (try? prefix.checkResourceIsReachable()) == true {
//			let prefixedPath = path.map { item in "\(prefix)/\(item)" }
//			path.insert(contentsOf: prefixedPath, at: 0)
//		}
		return path.joined(separator: ":")
	}()

	@objc static let primaryDebianArchitecture: String = {
		// TODO: We should ask dpkg instead of hardcoding
		#if targetEnvironment(macCatalyst)
		return "darwin"
		#else
		return "iphoneos-arm"
		#endif
	}()

	// MARK: - Distro/Jailbreak

	private class func isRegularFile(path: String) -> Bool {
		var isDir: ObjCBool = false
		return FileManager.default.fileExists(atPath: path, isDirectory: &isDir) && !isDir.boolValue
	}

	private class func isRegularDirectory(path: String) -> Bool {
		var isDir: ObjCBool = false
		return FileManager.default.fileExists(atPath: path, isDirectory: &isDir) && isDir.boolValue
	}

	@objc static let isCheckrain  = !isSimulated && isRegularFile(path: "/.bootstrapped")
	@objc static let isChimera    = !isSimulated && isRegularDirectory(path: "/chimera")
	@objc static let isElectra    = !isSimulated && isRegularDirectory(path: "/electra")
	@objc static let isUncover    = !isSimulated && isRegularFile(path: "/.installed_unc0ver")
	@objc static let isOdyssey    = !isSimulated && isRegularFile(path: "/.installed_odyssey")
	@objc static let isTaurine    = !isSimulated && isRegularFile(path: "/.installed_taurine")
	@objc static let hasProcursus = !isSimulated && isRegularFile(path: "/.procursus_strapped")

	@objc static let jailbreakType: String = {
		if isOdyssey {
			return "Odyssey"
		} else if isCheckrain {
			return "checkra1n"
		} else if isChimera {
			return "Chimera"
		} else if isElectra {
			return "Electra"
		} else if isUncover {
			return "unc0ver"
		}
		return "Unknown"
	}()

}