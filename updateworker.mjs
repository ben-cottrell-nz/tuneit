WorkerScript.onMessage = function(message) {
    var fftValues = message.outputBufferList;
//    for (var i=0;i<message.numFrames;i++) {
//        fftValues.push(message.outputBufferList[i])
//    }
    WorkerScript.sendMessage( { result: fftValues } )
}
