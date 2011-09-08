#ifndef VIDEO_HPP_
#define VIDEO_HPP_

class Video
{
public:
	Video();
	~Video();
	void clear();
	void write(char *cp);
	void put(char c);
private:
	unsigned short *videomem;
	unsigned int off;
	unsigned int pos;
}; 

#endif // VIDEO_HPP_
