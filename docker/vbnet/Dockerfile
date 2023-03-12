FROM mcr.microsoft.com/dotnet/sdk:7.0

# install nodejs
#RUN curl -sL https://deb.nodesource.com/setup_12.x | bash - \
#    && apt-get install -y nodejs
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y vim

# source
WORKDIR /usr/local/vbnet/
