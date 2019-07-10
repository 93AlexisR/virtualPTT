Abandoned project from 2 years ago when I had first started learning. It virtualizes a key-press when the user speaks such that it acts like a push-to-talk for software that don't have proper voice-activation.  

I will pick this project back up once I am done studying Deitel learning C++

The voice detection could be made in two ways: 

Both methods foremost require a calibration process which is a sampling period during which the program determines a range of vocal frequencies at which it should activate the buttong-press

Method 1: 
Record user's microphone data
Store user's recording as a buffer 
if sound data matches signature expected for user's voice
Virtualize a microphone device and output the buffered data

Method 2: 
Rather than buffering the data to a virtual microphone, the button-press would be done in real time 

The first method will always lose some information as before the user reaches a frequency that the program recognizes as the user's, some time will have elapsed such that the push to talk is pressed after the user spoke (naturally) 

the second method is better but the overhead might be too much; need to look into it. 
