#include "TextureLoader.h"

TextureLoader texLoader;

GLuint TextureLoader::loadTexture(const char* path)
{
	glGenTextures(1, &texLoader.ID);
	glBindTexture(GL_TEXTURE_2D, texLoader.ID);


	int width, height, colorChannels;
	unsigned char* data = stbi_load(path, &width, &height, &colorChannels, 0);
	if (data)
	{
		GLenum format;
		if (colorChannels == 1) format = GL_RED;
		else if (colorChannels == 3) format = GL_RGB;
		else if (colorChannels == 4) format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);


		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	else
	{
		std::cout << "ERROR: Texture failed to load at path: " << path << std::endl;
	}

	stbi_image_free(data);
	return texLoader.ID;
}