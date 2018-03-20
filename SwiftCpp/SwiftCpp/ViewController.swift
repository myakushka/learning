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

        let cpp = CppWrapper()
        let int = cpp.testInt()
        os_log("%d", int)
        // Do any additional setup after loading the view.
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

