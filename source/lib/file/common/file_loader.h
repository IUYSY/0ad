#ifndef INCLUDED_FILE_LOADER
#define INCLUDED_FILE_LOADER

struct IFileLoader
{
	virtual ~IFileLoader();

	virtual unsigned Precedence() const = 0;
	virtual char LocationCode() const = 0;

	virtual LibError Load(const std::string& name, shared_ptr<u8> buf, size_t size) const = 0;
};

typedef shared_ptr<IFileLoader> PIFileLoader;

#endif	// #ifndef INCLUDED_FILE_LOADER
