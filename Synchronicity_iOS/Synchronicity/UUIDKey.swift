//
//  UUIDKey.swift
//  Basic Chat
//
//  Created by Trevor Beaton on 12/3/16.
//  Copyright © 2016 Vanguard Logic LLC. All rights reserved.
//

import CoreBluetooth
//Uart Service uuid


let kBLEService_UUID = "19B10000-E8F2-537E-4F6C-D104768A1214"
let kBLE_Characteristic_uuid_Tx = "19B10001-E8F2-537E-4F6C-D104768A1214"
let kBLE_Characteristic_uuid_Rx = "19B10001-E8F2-537E-4F6C-D104768A1214"
let MaxCharacters = 20

let BLEService_UUID = CBUUID(string: kBLEService_UUID)
let BLE_Characteristic_uuid_Tx = CBUUID(string: kBLE_Characteristic_uuid_Tx)//(Property = Write without response)
let BLE_Characteristic_uuid_Rx = CBUUID(string: kBLE_Characteristic_uuid_Rx)// (Property = Read/Notify)
