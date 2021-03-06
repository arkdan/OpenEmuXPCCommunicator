/*
 Copyright (c) 2013, OpenEmu Team

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

// Only use this class from the main application.
// The class sets up the agent that will allow you to communicate with background processes.
@interface OEXPCCAgentConfiguration : NSObject

+ (OEXPCCAgentConfiguration *)defaultConfiguration;
- (void)tearDownAgent;

// Directory containing the agent binaries (Application Support).
// If for any reason -tearDownAgent hasn't been called on app termination, you may use this method
// to cleanup the folder.
+ (NSString *)agentsDirectory;

@property(readonly) NSString *serviceName;

// You need to pass two arguments to processes you want to connect to from the process
// initiating the connection: the service name argument and the process identifier
// argument. You obtain the former using -agentServiceNameProcessArgument and use
// -processIdentifierArgumentForIdentifier: to generate the latter. The identifier
// must be unique so it's preferrable to use NSUUID to generate it.
- (NSString *)agentServiceNameProcessArgument;
- (NSString *)processIdentifierArgumentForIdentifier:(NSString *)identifier;

@end
