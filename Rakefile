task :build do 
  mkdir_p 'build'
  chdir 'build' do 
    system 'cmake', '..'
    system 'make'
  end
  symlink 'build/compile_commands.json', '.'
rescue Errno::EEXIST 
  puts "File exists!"
rescue => err
  pp err
end

task :default => [:build]
