func hashIds(_ ids: [Int32]) -> Int32 {
    var acc: UInt32 = 0
    
    for id in ids {
        let low = UInt32(UInt32(bitPattern: id) & (0xffffffff as UInt32))
        let high = UInt32((UInt32(bitPattern: id) >> 32) & (0xffffffff as UInt32))
        
        acc = (acc &* 20261) &+ high
        acc = (acc &* 20261) &+ low
    }
    return Int32(bitPattern: acc & UInt32(0x7FFFFFFF))
}

func hashIdsOpt(_ ids: [Int32]) -> Int32 {
    var acc: UInt32 = 0

    for id in ids {
        acc = (acc &* 20261) &+ UInt32(bitPattern: id)
    }
    return Int32(bitPattern: acc & UInt32(0x7FFFFFFF))
}

let arr: [Int32] = [1, 2, 3, 4, 5]
print(hashIds(arr))
print(hashIdsOpt(arr))
