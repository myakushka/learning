//
//  ViewController.swift
//  SwiftCpp
//
//  Created by Женя on 18/03/2018.
//  Copyright © 2018 Myakushka Production. All rights reserved.
//

import Cocoa
import os.log

class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        let cppWrapper = CppWrapper()
        // get int
        let int = cppWrapper.getInt()
        os_log("%d", int)
        // get string
        let string = cppWrapper.getString();
        os_log("%@", string);
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

